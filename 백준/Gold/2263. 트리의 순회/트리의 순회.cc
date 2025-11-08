#include <iostream>
#include <vector>

#define MAX_N 100000

#define LEFT 0
#define RIGHT 1

using namespace std;

int N;
int root, g[MAX_N + 1][2];
int postorder[MAX_N];
int posIn[MAX_N];
vector<int> ans;

void makeTree(int curr, int s, int e){
    
    int p = e - 1;
    int cntRight = 0;
    while(p >= s && posIn[curr] < posIn[postorder[p]]){
        ++cntRight;
        --p;
    }
    
    if(cntRight > 0){
        g[curr][RIGHT] = postorder[e - 1];
        makeTree(g[curr][RIGHT], p + 1, e - 1);
    }

    if(p >= s){
        g[curr][LEFT] = postorder[p]; // p는 s보다 작거나(왼자식 없음) or s이상(왼자식 위치)
        makeTree(g[curr][LEFT], s, p);
    }
    
    return;
}

void preorder(int curr){
    ans.push_back(curr);
    if(g[curr][LEFT] != 0) preorder(g[curr][LEFT]);
    if(g[curr][RIGHT] != 0) preorder(g[curr][RIGHT]);
    return;
}

int main(){
    cin >> N;
    
    int node;
    for(int i=0; i<N; i++){
        cin >> node;
        posIn[node] = i;
    }
    for(int i=0; i<N; i++){
        cin >> postorder[i];
    }
    
    root = postorder[N - 1];
    makeTree(root, 0, N - 1);
    preorder(root);
    
    for(int curr : ans) cout << curr << ' ';
    
    return 0;
}


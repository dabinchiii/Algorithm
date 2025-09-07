#include <iostream>
#include <cmath>
#include <algorithm>

#define INF 1000000001

using namespace std;

struct treeNode{
    int idx, value;
};

int N, M;
treeNode *tree;
int arr[100001];

void makeTree(int node, int start, int end){
    if(start == end){ // 리프
        tree[node] = {start, arr[start]};
        return;
    }
    
    int mid = (start + end) / 2;
    int leftNode = 2 * node;
    int rightNode = 2 * node + 1;
    
    makeTree(leftNode, start, mid);
    makeTree(rightNode, mid + 1, end);
    
    if(tree[leftNode].value <= tree[rightNode].value){
        tree[node] = tree[leftNode];
    }
    else{
        tree[node] = tree[rightNode];
    }
    
    return;
}

void update(int node, int start, int end, int idx, int value){
    if(start > idx || end < idx) return; // 범위에 포함되지 X
    
    if(start == end && start == idx){
        tree[node].value = value;
        return;
    }
    
    int mid = (start + end) / 2;
    int leftNode = 2 * node;
    int rightNode = 2 * node + 1;
    
    update(leftNode, start, mid, idx, value);
    update(rightNode, mid + 1, end, idx, value);
    
    if(tree[leftNode].value <= tree[rightNode].value){
        tree[node] = tree[leftNode];
    }
    else{
        tree[node] = tree[rightNode];
    }
    
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    
    int h = ceil(log2(N)) + 1;
    tree = new treeNode[1 << h];
    
    makeTree(1, 1, N);
    
    cin >> M;
    
    int q;
    for(int i=0; i<M; i++){
        cin >> q;
        
        if(q == 1){
            int i, v;
            cin >> i >> v;
            update(1, 1, N, i, v);
        }
        else{
            printf("%d\n", tree[1].idx);
        }
    }
    
    return 0;
}

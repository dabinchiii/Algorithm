#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_N 200000

using namespace std;

struct node{
    int idx, c, s;
};

bool comp(node &a, node &b){
    return a.s < b.s;
}
int N;
long long ans[MAX_N + 1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    vector<node> v;
    int color, size;
    for(int i=1; i<=N; i++){
        cin >> color >> size;
        v.push_back({i, color, size});
    }
    
    sort(v.begin(), v.end(), comp);
    
    vector<long long> psum(N + 1, 0);
    long long total = 0;
    queue<node> q;
    int currSize = 0;
    
    for(node curr : v){
        if(curr.s != currSize){
            while(!q.empty()){
                node f = q.front();
                q.pop();
                total += f.s;
                psum[f.c] += f.s;
                
            }
            
        }
        q.push(curr);
        currSize = curr.s;
        ans[curr.idx] = total - psum[curr.c];
    }
    
    for(int i=1; i<=N; i++) cout << ans[i] << '\n';
    
    return 0;
}

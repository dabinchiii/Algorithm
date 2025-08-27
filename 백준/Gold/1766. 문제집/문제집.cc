#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 32000

using namespace std;

int N, M;
vector<int> g[MAX_N + 1];
int inDegree[MAX_N + 1];

vector<int> ans;

void solve(){
    priority_queue<int> pq;
    
    for(int i=1; i<=N; i++){
        if(inDegree[i] == 0) pq.push(-i);
    }
    
    while(!pq.empty()){
        int curr = -pq.top();
        pq.pop();
        
        ans.push_back(curr);
        
        for(int nxt : g[curr]){
            if(--inDegree[nxt] == 0) pq.push(-nxt);
        }
    }
    return;
}

int main(){
    cin >> N >> M;
    
    int A, B;
    for(int i=0; i<M; i++){
        cin >> A >> B;
        g[A].push_back(B);
        inDegree[B]++;
    }
    
    solve();
    
    for(int curr : ans){
        cout << curr << ' ';
    }
    
    return 0;
}



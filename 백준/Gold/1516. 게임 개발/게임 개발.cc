#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 500

using namespace std;

int N;
int cost[MAX_N + 1];
vector<int> g[MAX_N + 1], rg[MAX_N + 1];
int inDegree[MAX_N + 1];

int ans[MAX_N + 1];

void solve(){
    queue<int> q;
    
    for(int i=1; i<=N; i++){
        if(inDegree[i] != 0) continue;
        q.push(i);
        ans[i] = cost[i];
    }
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int nxt : g[curr]){
            if(--inDegree[nxt] == 0){
                q.push(nxt);
                
                int maxT = -1;
                for(int x : rg[nxt]){
                    maxT = max(maxT, ans[x]);
                }
                ans[nxt] = maxT + cost[nxt];
            }
        }
    }
    
    return;
}

int main(){
    cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> cost[i];
        
        int u;
        while(true){
            cin >> u;
            if(u == -1) break;
            
            g[u].push_back(i);
            rg[i].push_back(u);
            inDegree[i]++;
        }
    }
    
    solve();
    
    for(int i=1; i<=N; i++){
        cout << ans[i] << '\n';
    }
}

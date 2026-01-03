#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100000
#define MAX_K 1000000

#define min(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

int N, M, s, e;
vector<pair<int, int>> g[MAX_N + 1];
int ans;

void solve(){
    priority_queue<pair<int, int>> pq; // max
    vector<bool> visited(N + 1, false);
    
    pq.push({MAX_K, s});
    
    while(!pq.empty()){
        int currW = pq.top().first;
        int currV = pq.top().second;
        pq.pop();
        
        if(currV == e){
            ans = currW;
            return;
        }
        
        if(visited[currV]) continue;
        
        visited[currV] = true;
        
        for(auto nxt : g[currV]){
            if(!visited[nxt.first]) pq.push({min(currW, nxt.second), nxt.first});
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> s >> e;
    
    int u, v, k;
    for(int i=0; i<M; i++){
        cin >> u >> v >> k;
        g[u].push_back({v, k});
        g[v].push_back({u, k});
    }
    
    solve();
    cout << ans;
    
    return 0;
}

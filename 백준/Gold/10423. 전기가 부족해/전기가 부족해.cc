#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1000
#define MAX_K 1000

using namespace std;

int N, M, K;
vector<pair<int, int>> g[MAX_N + 1];
int power[MAX_K];
int ans;

void solve(){
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(N + 1, false);
    int cnt = 0;
    
    for(int i=0; i<K; i++){
        pq.push({0, power[i]});
    }
    
    while(!pq.empty() && cnt < N){
        int currW = -pq.top().first;
        int currV = pq.top().second;
        pq.pop();
        
        if(visited[currV]) continue;
        
        visited[currV] = true;
        ans += currW;
        ++cnt;
        
        for(auto nxt : g[currV]){
            if(!visited[nxt.first]) pq.push({-nxt.second, nxt.first});
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> K;
    
    for(int i=0; i<K; i++) cin >> power[i];
    
    int u, v, w;
    for(int i=0; i<M; i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

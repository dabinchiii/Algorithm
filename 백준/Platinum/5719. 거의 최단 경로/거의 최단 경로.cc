#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 500
#define INF 10000000

using namespace std;

int n, m, s, d;
vector<pair<short, int>> g[MAX_N];
int ans;

void init(){
    for(int i=0; i<MAX_N; i++){
        g[i].clear();
    }
    ans = 0;
    return;
}

void solve(){
    vector<int> dist(n, INF);
    vector<vector<short>> parents(n);
    priority_queue<pair<int, short>> q;
    
    dist[s] = 0;
    q.push({0, s}); // {거리, 노드}
    
    while(!q.empty()){
        short currV = q.top().second;
        int currDist = -q.top().first;
        q.pop();
        
        if(currDist > dist[currV]) continue;
        
        for(auto nxt : g[currV]){
            short nxtV = nxt.first;
            int nxtDist = currDist + nxt.second;
            
            if(dist[nxtV] > nxtDist){
                dist[nxtV] = nxtDist;
                parents[nxtV].clear();
                q.push({-nxtDist, nxtV});
            }
            if(dist[nxtV] == nxtDist){
                parents[nxtV].push_back(currV);
            }
        }
    }
    
    vector<vector<bool>> blocked(n, vector<bool>(n, false));
    vector<bool> visited(n, false);
    queue<int> vq;
    vq.push(d);
    visited[d] = true;
    while(!vq.empty()){
        short curr = vq.front();
        vq.pop();
        
        for(short prev : parents[curr]){
            blocked[prev][curr] = true;
            
            if(!visited[prev]){
                vq.push(prev);
                visited[prev] = true;
            }
        }
    }
    
    dist = vector<int>(n, INF);
    
    dist[s] = 0;
    q.push({0, s});
    
    while(!q.empty()){
        short currV = q.top().second;
        int currDist = -q.top().first;
        q.pop();
        
        if(currDist > dist[currV]) continue;
        
        for(auto nxt : g[currV]){
            short nxtV = nxt.first;
            int nxtDist = currDist + nxt.second;
            
            if(blocked[currV][nxtV]) continue;
            
            if(dist[nxtV] > nxtDist){
                dist[nxtV] = nxtDist;
                q.push({-nxtDist, nxtV});
            }
        }
    }
    
    if(dist[d] == INF) ans = -1;
    else ans = dist[d];
    
    return;
}
int main(){
    while(true){
        init();
        
        cin >> n >> m;
        if(n == 0) break;
        
        cin >> s >> d;
        
        short u, v;
        int p;
        for(int i=0; i<m; i++){
            cin >> u >> v >> p;
            g[u].push_back({v, p});
        }
        
        solve();
        
        cout << ans << '\n';
    }
    
    return 0;
}

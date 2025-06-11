#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 50000000

using namespace std;

int n, m;
vector<pair<int, int>> g[5001]; // g[0]: 더미
vector<int> home;
int ans;

void solve(){
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> q;
    
    q.push({0, 0});
    dist[0] = 0;
    
    while(!q.empty()){
        int currV = q.top().second;
        int currDist = -q.top().first;
        q.pop();
        
        if(dist[currV] < currDist) continue;
        
        for(auto nxt : g[currV]){
            int nxtV = nxt.first;
            int nxtDist = currDist + nxt.second;
            
            if(nxtDist < dist[nxtV]){
                dist[nxtV] = nxtDist;
                q.push({-nxtDist, nxtV});
            }
        }
    }
    
    sort(home.begin(), home.end());
    
    int minVal = INF, minV = -1;
    for(int v : home){
        if(dist[v] < minVal){
            minVal = dist[v];
            minV = v;
        }
    }
    ans = minV;
    
    return;
}
int main(){
    cin >> n >> m;
    
    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    int p, q;
    cin >> p >> q;
    
    int u;
    for(int i=0; i<p; i++){
        cin >> u;
        home.push_back(u);
    }
    for(int i=0; i<q; i++){
        cin >> u;
        g[0].push_back({u, 0});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

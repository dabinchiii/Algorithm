#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

struct gNode{
    int node, time, cost;
};
struct qNode{
    int node, time, cost;
};
struct comp{
    bool operator()(qNode a, qNode b){
        return (a.time > b.time);
    }
};

int n, t, m, l;
vector<gNode> g[101];
int ans;

void solve(){
    vector<vector<int>> dist(n + 1, vector<int>(10001, INF));
    priority_queue<qNode, vector<qNode>, comp> q; // {노드, 소요시간, 택시비}
    
    dist[1][0] = 0;
    q.push({1, 0, 0});
    
    while(!q.empty()){
        int currV = q.top().node;
        int currT = q.top().time;
        int currC = q.top().cost;
        q.pop();
        
        if(dist[currV][currC] < currT) continue;
        
        for(auto nxt : g[currV]){
            int nxtV = nxt.node;
            int nxtT = currT + nxt.time;
            int nxtC = currC + nxt.cost;
            
            if(nxtC > m) continue; // 예산 초과
            
            if(dist[nxtV][nxtC] > nxtT){
                dist[nxtV][nxtC] = nxtT;
                q.push({nxtV, nxtT, nxtC});
            }
        }
    }
    
    int minC = INF;
    for(int i=0; i<=m; i++){
        if(dist[n][i] <= t){
            minC = i;
            break;
        }
    }
    if(minC == INF) ans = -1;
    else ans = minC;
    
    return;
}

int main(){
    cin >> n >> t >> m >> l;
    
    int u, v, time, cost;
    for(int i=0; i<l; i++){
        cin >> u >> v >> time >> cost;
        g[u].push_back({v, time, cost});
        g[v].push_back({u, time, cost});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

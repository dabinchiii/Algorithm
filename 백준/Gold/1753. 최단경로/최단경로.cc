#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> g(V+1);
    int u, v, w;
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    vector<int> dist(V+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, K});
    dist[K] = 0;

    while(!q.empty()){
        int currV = q.top().second; // 현재 정점 (방문한 정점 중에서 dist값이 가장 작은 정점)
        int currCost = q.top().first;
        q.pop();

        for(int i=0; i<g[currV].size(); i++){
            int nxtV = g[currV][i].first;
            int nxtCost = g[currV][i].second;

            if(dist[nxtV] > dist[currV] + nxtCost){
                dist[nxtV] = dist[currV] + nxtCost;
                q.push({dist[nxtV], nxtV});
            }

        }
    }

    for(int i=1; i<=V; i++){
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}

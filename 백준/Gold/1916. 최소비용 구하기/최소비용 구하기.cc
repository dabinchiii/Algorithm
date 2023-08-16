#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n+1);
    int u, v, w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    int A, B;
    cin >> A >> B;

    vector<int> dist(n+1, INF);
    priority_queue<pair<int, int>> q;
    dist[A] = 0;
    q.push({0, A});

    while(!q.empty()){
        int currV = q.top().second;
        int currCost = -q.top().first;
        q.pop();

        if(dist[currV] < currCost) continue;

        for(int i=0; i<g[currV].size(); i++){
            int nxtV = g[currV][i].first;
            int nxtCost = g[currV][i].second;

            if(dist[nxtV] > dist[currV] + nxtCost){
                dist[nxtV] = dist[currV] + nxtCost;
                q.push({-dist[nxtV], nxtV});
            }
        }
    }

    cout << dist[B];

    return 0;
}

#include <bits/stdc++.h>
#define MAX_N 100000
#define INF 30000000000

using namespace std;

int n, m;
vector<int> visible(MAX_N);
vector<pair<int, long long>> g[MAX_N];
vector<long long> dis(MAX_N, INF);

void dijkstra(int start){
    priority_queue<pair<long long, int>> q;
    q.push({0, start});
    dis[start] = 0;

    while(!q.empty()){
        int currX = q.top().second;
        long long currDis = -q.top().first;
        q.pop();

        if(dis[currX] < currDis) continue;

        for(int i=0; i<g[currX].size(); i++){
            int nxtX = g[currX][i].first;
            long long nxtDis = currDis + g[currX][i].second;

            if(dis[nxtX] > nxtDis){
                dis[nxtX] = nxtDis;
                q.push({-nxtDis, nxtX});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> visible[i];
    }
    visible[n - 1] = 0;

    int a, b;
    long long t;
    for(int i=0; i<m; i++){
        cin >> a >> b >> t;

        if(visible[a] || visible[b]) continue;
        g[a].push_back({b, t});
        g[b].push_back({a, t});
    }

    dijkstra(0);

    if(dis[n - 1] == INF) cout << -1;
    else cout << dis[n - 1];

    return 0;
}

#include <bits/stdc++.h>
#define MAX_N 100000
#define INF LLONG_MAX

using namespace std;

int n, m, x, z, p;
vector<pair<int, long long>> g[MAX_N + 1];
vector<int> nodeY(MAX_N - 2);

vector<long long> dijkstra(int start){
    vector<long long> dis(n + 1, INF);
    priority_queue<pair<long long, int>> q;

    q.push({0, start});
    dis[start] = 0;

    while(!q.empty()){
        int currX = q.top().second;
        long long currDis = -q.top().first;
        q.pop();

        if(dis[currX] < currDis) continue;

        for(pair<int, long long> nxt : g[currX]){
            int nxtX = nxt.first;
            long long nxtDis = currDis + nxt.second;

            if(dis[nxtX] > nxtDis){
                dis[nxtX] = nxtDis;
                q.push({-nxtDis, nxtX});
            }
        }
    }

    return dis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int u, v;
    long long w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    cin >> x >> z >> p;

    for(int i=0; i<p; i++){
        cin >> nodeY[i];
    }

    vector<long long> disFromX = dijkstra(x);
    vector<long long> disFromZ = dijkstra(z);

    long long Answer = INF;
    for(int y : nodeY){
        if(disFromX[y] == INF || disFromZ[y] == INF) continue;
        Answer = min(Answer, disFromX[y] + disFromZ[y]);
    }

    cout << (Answer == INF ? -1 : Answer);

    return 0;
}

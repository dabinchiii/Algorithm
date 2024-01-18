#include <bits/stdc++.h>
#define MAX_N 100000
#define INF 1000000000

using namespace std;

int n, m;
vector<pair<int, int>> g[MAX_N + 1];
int x, y, z;

vector<int> dijkstra(int start){
    vector<int> dis(n + 1, INF);
    priority_queue<pair<int, int>> q;

    q.push({0, start});
    dis[start] = 0;

    while(!q.empty()){
        int currNode = q.top().second;
        int currDis = -q.top().first;
        q.pop();

        if(dis[currNode] < currDis) continue;

        for(pair<int, int> nxt : g[currNode]){
            int nxtNode = nxt.first;
            int nxtDis = currDis + nxt.second;

            if(dis[nxtNode] > nxtDis){
                dis[nxtNode] = nxtDis;
                q.push({-nxtDis, nxtNode});
            }
        }

    }

    return dis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int u, v, w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    cin >> x >> y >> z;

    vector<int> disFromX = dijkstra(x);
    vector<int> disFromY = dijkstra(y);
    int Answer1;
    if(disFromX[y] == INF || disFromY[z] == INF) Answer1 = -1;
    else Answer1 = disFromX[y] + disFromY[z];

    for(int i=1; i<=n; i++){
        for(int j=0; j<g[i].size(); j++){
            if(g[i][j].first != y) continue;
            g[i][j].second = INF;
        }
    }

    disFromX = dijkstra(x);
    int Answer2 = disFromX[z];

    cout << Answer1 << ' ' << (Answer2 == INF ? -1 : Answer2);

    return 0;
}

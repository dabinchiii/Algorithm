#include <bits/stdc++.h>
#define MAX_N 1000
#define INF 100000000

using namespace std;

int n, m, a, b;
vector<vector<int>> weight(MAX_N + 1, vector<int>(MAX_N + 1, INF));

void solve(){
    vector<bool> visited(n + 1, false);
    vector<int> dis = weight[a];
    vector<int> prev(n + 1, -1);

    visited[a] = true;
    for(int i=1; i<=n; i++){
        if(dis[i] == INF || i == a) continue;
        prev[i] = a;
    }

    for(int i=0; i<n - 1; i++){
        int minValue = INF, minNode = 0;
        for(int j=1; j<=n; j++){
            if(visited[j]) continue;
            if(dis[j] < minValue){
                minNode = j;
                minValue = dis[j];
            }
        }

        visited[minNode] = true;
        for(int j=1; j<=n; j++){
            if(visited[j]) continue;
            if(dis[j] > dis[minNode] + weight[minNode][j]){
                dis[j] = dis[minNode] + weight[minNode][j];
                prev[j] = minNode;
            }
        }

    }

    vector<int> path;
    int curr = b;
    while(curr != -1){
        path.push_back(curr);
        curr = prev[curr];
    }

    cout << dis[b] << '\n';
    cout << path.size() << '\n';
    for(int i=path.size() - 1; i>=0; i--){
        cout << path[i] << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        weight[i][i] = 0;
    }
    int u, v, w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        weight[u][v] = min(weight[u][v], w);
    }

    cin >> a >> b;

    solve();

    return 0;
}

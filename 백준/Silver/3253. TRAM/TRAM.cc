#include <bits/stdc++.h>
#define MAX_N 100
#define INF 1000

using namespace std;

int n, a, b;
vector<vector<int>> w(MAX_N + 1, vector<int>(MAX_N + 1, INF));
vector<int> dis(MAX_N + 1);

void dijkstra(int start){
    vector<bool> visited(n + 1, false);

    dis = w[start];
    visited[start] = true;

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
            dis[j] = min(dis[j], dis[minNode] + w[minNode][j]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;

    int k, u;
    for(int i=1; i<=n; i++){
        w[i][i] = 0;

        cin >> k;
        for(int j=0; j<k; j++){
            cin >> u;
            w[i][u] = (j == 0 ? 0 : 1);
        }
    }

    dijkstra(a);

    if(dis[b] == INF) cout << -1;
    else cout << dis[b];

    return 0;
}

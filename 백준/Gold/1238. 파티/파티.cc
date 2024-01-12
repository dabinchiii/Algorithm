#include <bits/stdc++.h>
#define MAX_N 1000
#define INF 1000000

using namespace std;

int n, m, x;
vector<vector<int>> w(MAX_N + 1, vector<int>(MAX_N + 1, INF));
vector<vector<int>> rw(MAX_N + 1, vector<int>(MAX_N + 1, INF));
vector<int> sum(MAX_N + 1, 0);

vector<int> dijkstra(int start, vector<vector<int>> &weight){
    vector<int> dis(n + 1);
    vector<bool> visited(n + 1, false);

    dis = weight[start];
    visited[start] = true;

    for(int i=0; i<n-1; i++){
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
            dis[j] = min(dis[j], dis[minNode] + weight[minNode][j]);
        }
    }

    return dis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;

    for(int i=1; i<=n; i++){
        w[i][i] = 0;
        rw[i][i] = 0;
    }

    int u, v, t;
    for(int i=0; i<m; i++){
        cin >> u >> v >> t;
        w[u][v] = t;
        rw[v][u] = t;
    }

    vector<int> disFromX = dijkstra(x, w);
    vector<int> disToX = dijkstra(x, rw);

    int Answer = -1;
    for(int i=1; i<=n; i++){
        Answer = max(Answer, disToX[i] + disFromX[i]);
    }
    cout << Answer;

    return 0;
}

#include <bits/stdc++.h>
#define MAX_N 200
#define INF 2000000

using namespace std;

int n, m;
vector<vector<int>> weight(MAX_N + 1, vector<int>(MAX_N + 1, INF));

vector<int> dijkstra(int start){
    vector<bool> visited(n + 1, false);
    vector<int> dis, first(n + 1, 0);

    dis = weight[start];
    for(int i=1; i<=n; i++){
        if(dis[i] != INF && i != start){
            first[i] = i;
        }
    }
    visited[start] = true;

    for(int i=0; i<n - 1; i++){
        int minValue = INF, minNode = -1;
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
                first[j] = first[minNode];
            }
        }
    }

    return first;
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
        weight[u][v] = weight[v][u] = w;
    }

    vector<vector<int>> Answer(n + 1);
    for(int i=1; i<=n; i++){
        Answer[i] = dijkstra(i);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) cout << '-';
            else cout << Answer[i][j];
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
#define MAX_N 800
#define INF 200000000

using namespace std;

int n, e;
vector<vector<int>> w(MAX_N + 1, vector<int>(MAX_N + 1, INF));

vector<int> dijkstra(int start){
    vector<int> dis;
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

    return dis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;

    for(int i=1; i<=n; i++){
        w[i][i] = 0;
    }

    int a, b, c;
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        w[a][b] = c;
        w[b][a] = c;
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> disFromV1 = dijkstra(v1);
    vector<int> disFromV2 = dijkstra(v2);

    long long Answer = disFromV1[v2];
    Answer += min(disFromV1[1] + disFromV2[n], disFromV2[1] + disFromV1[n]);

    cout << (Answer >= INF ? -1 : Answer);

    return 0;
}

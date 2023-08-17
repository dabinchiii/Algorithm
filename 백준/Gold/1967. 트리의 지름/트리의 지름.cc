// DFS, 머리끄댕이
// 루트에서 가장 먼 정점 찾고 => 지름의 한 끝
// 찾은 정점에서 가장 먼 정점 찾음 => 지름의 다른 한 끝

#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int n;
vector<vector<pair<int, int>>> g(MAX);
vector<bool> visited(MAX, false);
int currDist, maxDist, edge;

void dfs(int v){
    visited[v] = true;
    if(currDist > maxDist){
        maxDist = currDist;
        edge = v;
    }

    for(int i=0; i<g[v].size(); i++){
        int nxtV = g[v][i].first;
        int nxtDist = g[v][i].second;

        if(visited[nxtV]) continue;

        currDist += nxtDist;
        dfs(nxtV);
        currDist -= nxtDist;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int u, v, w;
    for(int i=0; i<n-1; i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    currDist = 0;
    maxDist = -1;
    dfs(1);

    for(int i=1; i<=n; i++){
        visited[i] = false;
    }
    currDist = 0;
    maxDist = -1;
    dfs(edge);

    cout << maxDist;

    return 0;
}

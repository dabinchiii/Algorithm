#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;

int n, m;
vector<vector<pair<int, int>>> g(MAX_N + 1);
vector<bool> visited(MAX_N + 1);
int from, to;
int Answer;

void dfs(int curr, int dist){
    visited[curr] = true;

    if(curr == to){
        Answer = dist;
        return;
    }

    for(pair<int, int> x : g[curr]){
        if(!visited[x.first]){
            dfs(x.first, dist + x.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int u, v, w;
    for(int i=0; i<n-1; i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for(int i=0; i<m; i++){
        cin >> from >> to;

        for(int j=1; j<=n; j++){
            visited[j] = false;
        }

        dfs(from, 0);

        cout << Answer << '\n';
    }

    return 0;
}

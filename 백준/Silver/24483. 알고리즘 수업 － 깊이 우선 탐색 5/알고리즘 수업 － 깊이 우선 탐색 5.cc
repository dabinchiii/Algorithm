#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;

int n, m, r;
vector<vector<int>> g(MAX_N + 1);
vector<bool> visited(MAX_N + 1);
long long cnt;
long long Answer;

void dfs(int curr, int depth){
    visited[curr] = true;

    cnt += 1;
    Answer += depth * cnt;

    for(int nxt : g[curr]){
        if(!visited[nxt]){
            dfs(nxt, depth + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;

    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        sort(g[i].begin(), g[i].end());
    }

    dfs(r, 0);

    cout << Answer;

    return 0;
}

#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

int n, r, q;
vector<int> g[MAX_N + 1];
vector<int> cntChild(MAX_N + 1, 1);
bool visited[MAX_N + 1];

int dfs(int root){
    visited[root] = true;

    for(int node : g[root]){
        if(visited[node]) continue;
        cntChild[root] += dfs(node);
    }

    return cntChild[root];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> q;

    int u, v;
    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(r);

    for(int i=0; i<q; i++){
        cin >> u;
        cout << cntChild[u] << '\n';
    }

    return 0;
}

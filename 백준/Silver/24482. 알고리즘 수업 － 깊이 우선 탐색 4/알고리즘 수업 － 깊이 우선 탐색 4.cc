#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;

int n, m, r;
vector<vector<int>> g(MAX_N + 1);
vector<int> depth(MAX_N + 1, -1); // -1: 방문되지 않음

void dfs(int currNode, int currDepth){
    depth[currNode] = currDepth; // 방문 표시

    for(int nxt : g[currNode]){
        if(depth[nxt] != -1) continue; // 이미 방문한 노드
        dfs(nxt, currDepth + 1);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;

    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        // 양방향 간선
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        sort(g[i].begin(), g[i].end(), greater<int>());
    }

    dfs(r, 0);

    for(int i=1; i<=n; i++){
        cout << depth[i] << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
#define MAX_N 2000

using namespace std;

int n, m;
vector<int> g[MAX_N];
bool visited[MAX_N];
int ans;

void dfs(int curr, int depth){
    if(depth == 4){
        ans = true;
        return;
    }

    for(int nxt : g[curr]){
        if(visited[nxt]) continue;
        
        visited[nxt] = true;
        dfs(nxt, depth + 1);
        visited[nxt] = false;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        if(ans) break;
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
    }

    cout << (ans ? 1 : 0);

    return 0;
}

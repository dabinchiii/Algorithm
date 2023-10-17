#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;

int n, m, x;
vector<vector<int>> g(MAX_N);
vector<bool> visited(MAX_N);
int Answer;

void dfs(int curr){
    visited[curr] = true;

    for(int nxt : g[curr]){
        if(!visited[nxt]){
            Answer++;
            dfs(nxt);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        g[b].push_back(a);
    }

    cin >> x;

    dfs(x);

    cout << Answer;

    return 0;
}

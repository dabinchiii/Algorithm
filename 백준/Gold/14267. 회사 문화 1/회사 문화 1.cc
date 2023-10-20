#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;

int n, m;
vector<vector<int>> g(MAX_N + 1);
vector<int> comp(MAX_N + 1, 0);

void dfs(int curr, int w){
    comp[curr] += w;

    for(int nxt : g[curr]){
        dfs(nxt, comp[curr]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int super;
    for(int i=1; i<=n; i++){
        cin >> super;

        if(super == -1) continue;
        g[super].push_back(i);
    }

    int emp, w;
    for(int i=0; i<m; i++){
        cin >> emp >> w;
        comp[emp] += w;
    }

    dfs(1, 0);

    for(int i=1; i<=n; i++){
        cout << comp[i] << ' ';
    }

    return 0;
}

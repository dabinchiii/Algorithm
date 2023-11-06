#include <bits/stdc++.h>
#define MAX_N 10000
#define MAX_Ai 10000
using namespace std;

int n, m, k;
vector<int> arr(MAX_N + 1);
vector<vector<int>> g(MAX_N + 1);
vector<bool> visited(MAX_N + 1, false);
int cnt, currMin;
int cost;

void dfs(int curr){
    visited[curr] = true;
    cnt++;
    currMin = min(currMin, arr[curr]);

    for(int nxt : g[curr]){
        if(!visited[nxt]){
            dfs(nxt);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int v, w;
    for(int i=0; i<m; i++){
        cin >> v >> w;
        g[v].push_back(w);
        g[w].push_back(v);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            currMin = MAX_Ai + 1;
            dfs(i);
            cost += currMin;
        }
    }

    if(cnt == n && cost <= k) cout << cost;
    else cout << "Oh no";

    return 0;
}

#include <bits/stdc++.h>
#define NEG_INF -100000
#define MAX_N 100

using namespace std;

int n, m;
vector<vector<bool>> g(MAX_N + 1, vector<bool>(MAX_N + 1, false));

bool bfsToN(int start){
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == n) return true;

        for(int i=1; i<=n; i++){
            if(!g[curr][i]) continue;
            if(visited[i]) continue;

            visited[i] = true;
            q.push(i);
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;

    vector<pair<pair<int, int>, int>> e;
    int u, v, w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        e.push_back({{u, v}, w});
        g[u][v] = true;
    }

    vector<int> money(n + 1, NEG_INF);
    vector<vector<int>> prev(n + 1);

    money[1] = 0;
    for(int i=1; i<=n; i++){
        prev[i].push_back(i);
    }

    for(int i=1; i<=n - 1; i++){
        for(auto x : e){
            int u = x.first.first;
            int v = x.first.second;
            int w = x.second;

            if(money[u] == NEG_INF) continue;
            if(money[v] < money[u] + w){
                money[v] = money[u] + w;
                prev[v] = prev[u];
                prev[v].push_back(v);
            }
        }
    }

    bool cycle = false;
    vector<bool> isInCycle(n + 1, false);
    for(auto x : e){
        int u = x.first.first;
        int v = x.first.second;
        int w = x.second;

        if(money[u] == NEG_INF) continue;
        if(money[v] < money[u] + w){
            cycle = true;
            isInCycle[v] = true;
        }
    }

    bool flag = false;
    for(int i=1; i<=n; i++){
        if(!isInCycle[i]) continue;
        if(bfsToN(i)) flag = true;
    }

    if(money[n] == NEG_INF || flag) cout << -1;
    else{
        for(int x : prev[n]) cout << x << ' ';
    }

    return 0;
}

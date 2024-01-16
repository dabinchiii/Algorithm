#include <bits/stdc++.h>
#define NEG_INF -50000000000000
#define MAX_N 50

using namespace std;

int n, m, a, b;
vector<pair<pair<int, int>, long long>> e;
vector<vector<bool>> g(MAX_N, vector<bool>(MAX_N, false));

bool bfsToB(int start){
    queue<int> q;
    vector<bool> visited(n, false);

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == b) return true;

        for(int i=0; i<n; i++){
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

    cin >> n >> a >> b >> m;

    int from, to;
    long long w;
    for(int i=0; i<m; i++){
        cin >> from >> to >> w;
        e.push_back({{from, to}, -w});
        g[from][to] = true;
    }

    vector<long long> income(n);
    for(int i=0; i<n; i++){
        cin >> income[i];
    }
    for(int i=0; i<e.size(); i++){
        e[i].second += income[e[i].first.second];
    }

    vector<long long> cost(n, NEG_INF);
    cost[a] = income[a];

    for(int i=1; i<=n-1; i++){
        for(auto x : e){
            int u = x.first.first;
            int v = x.first.second;
            int w = x.second;

            if(cost[u] == NEG_INF) continue;
            cost[v] = max(cost[v], cost[u] + w);
        }
    }

    bool posCycle = false;
    vector<bool> isInCycle(n, false);
    for(auto x : e){
        int u = x.first.first;
        int v = x.first.second;
        int w = x.second;

        if(cost[u] == NEG_INF) continue;
        if(cost[v] < cost[u] + w){
            posCycle = true;
            isInCycle[v] = true;
        }
    }

    bool isGee = false;
    for(int i=0; i<n; i++){
        if(!isInCycle[i]) continue;
        if(bfsToB(i)) isGee = true;
    }

    if(cost[b] == NEG_INF) cout << "gg";
    else if(isGee) cout << "Gee";
    else cout << cost[b];

    return 0;
}

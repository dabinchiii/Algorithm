#include <bits/stdc++.h>
#define MAX_V 10000

using namespace std;

int v, e;
vector<pair<int, int>> g[MAX_V + 1];

int prim(){
    priority_queue<pair<int, int>> q;
    bool visited[v + 1];
    int cost = 0;

    for(int i=1; i<=v; i++){
        visited[i] = false;
    }

    q.push({0, 1});

    while(!q.empty()){
        int u = q.top().second;
        int w = -q.top().first;
        q.pop();

        if(visited[u]) continue;
        visited[u] = true;
        cost += w;

        for(pair<int, int> nxt : g[u]){
            q.push({-nxt.second, nxt.first});
        }
    }

    return cost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;

    int a, b, c;
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    cout << prim();

    return 0;
}

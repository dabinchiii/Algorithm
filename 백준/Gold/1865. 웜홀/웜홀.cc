#include <bits/stdc++.h>
#define INF 5000000

using namespace std;

bool bellman(int n, vector<pair<pair<int, int>, int>> &e){
    vector<int> dis(n + 1, INF);

    for(int i=1; i<=n - 1; i++){
        for(auto x : e){
            int u = x.first.first;
            int v = x.first.second;
            int w = x.second;

            dis[v] = min(dis[v], dis[u] + w);
        }
    }

    for(auto x : e){
        int u = x.first.first;
        int v = x.first.second;
        int w = x.second;

        if(dis[v] > dis[u] + w)
            return true; // 음의 사이클 존재
    }
    return false;
}

void solve(){
    int n, m, w;
    cin >> n >> m >> w;

    vector<pair<pair<int, int>, int>> edges;
    int s, e, t;
    for(int i=0; i<m; i++){
        cin >> s >> e >> t;
        edges.push_back({{s, e}, t});
        edges.push_back({{e, s}, t});
    }
    for(int i=0; i<w; i++){
        cin >> s >> e >> t;
        edges.push_back({{s, e}, -t});
    }

    bool Answer = bellman(n, edges);
    cout << (Answer ? "YES" : "NO") << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        solve();
    }

    return 0;
}

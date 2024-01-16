#include <bits/stdc++.h>
#define INF 5000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, long long>> e;
    int a, b;
    long long c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        e.push_back({{a, b}, c});
    }

    vector<long long> dis(n + 1, INF);
    dis[1] = 0;

    for(int i=1; i<=n - 1; i++){
        for(auto x : e){
            int u = x.first.first;
            int v = x.first.second;
            long long w = x.second;

            if(dis[u] == INF) continue;
            dis[v] = min(dis[v], dis[u] + w);
        }
    }

    bool negCycle = false;
    for(auto x : e){
        int u = x.first.first;
        int v = x.first.second;
        long long w = x.second;

        if(dis[u] == INF) continue;
        if(dis[v] > dis[u] + w){
            negCycle = true;
            break;
        }
    }

    if(negCycle) cout << -1;
    else{
        for(int i=2; i<=n; i++){
            cout << (dis[i] == INF ? -1 : dis[i]) << '\n';
        }
    }

    return 0;
}

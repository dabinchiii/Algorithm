#include <bits/stdc++.h>
#define MAX_V 5000
#define INF 50000000

using namespace std;

int v, e, p;
vector<vector<pair<int, int>>> g(MAX_V + 1);

vector<int> dijkstra(int start){
    vector<int> dis(v + 1, INF);
    priority_queue<pair<int, int>> q;

    q.push({0, start});
    dis[start] = 0;

    while(!q.empty()){
        int currX = q.top().second;
        int currDis = -q.top().first;
        q.pop();

        if(dis[currX] < currDis) continue;

        for(pair<int, int> x : g[currX]){
            int nxtNode = x.first;
            int nxtDis = currDis + x.second;

            if(dis[nxtNode] > nxtDis){
                dis[nxtNode] = nxtDis;
                q.push({-nxtDis, nxtNode});
            }
        }
    }

    return dis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e >> p;

    int a, b, c;
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<int> disFrom1 = dijkstra(1);
    vector<int> disFromV = dijkstra(v);

    if(disFrom1[v] == disFrom1[p] + disFromV[p]) cout << "SAVE HIM";
    else cout << "GOOD BYE";

    return 0;
}

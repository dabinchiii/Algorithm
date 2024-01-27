#include <bits/stdc++.h>
#define MAX_V 10000
#define INF 100000000

using namespace std;

int v, e;
vector<pair<int, int>> g[MAX_V + 3]; // [v+1]: 맥날 더미, [v+2]: 스벅 더미

vector<int> dijkstra(int start){
    vector<int> dis(v + 3, INF);
    priority_queue<pair<int, int>> q;

    q.push({0, start});
    dis[start] = 0;

    while(!q.empty()){
        int currX = q.top().second;
        int currDis = -q.top().first;
        q.pop();

        if(dis[currX] < currDis) continue;

        for(pair<int, int> nxt : g[currX]){
            int nxtX = nxt.first;
            int nxtDis = currDis + nxt.second;

            if(dis[nxtX] > nxtDis){
                dis[nxtX] = nxtDis;
                q.push({-nxtDis, nxtX});
            }
        }
    }

    return dis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;

    int a, b, w;
    for(int i=0; i<e; i++){
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    vector<bool> isHouse(v + 1, true);

    int m, x;
    cin >> m >> x;
    for(int i=0; i<m; i++){
        cin >> a;
        g[v + 1].push_back({a, 0});
        isHouse[a] = false;
    }

    int s, y;
    cin >> s >> y;
    for(int i=0; i<s; i++){
        cin >> a;
        g[v + 2].push_back({a, 0});
        isHouse[a] = false;
    }

    vector<int> disFromMc = dijkstra(v + 1);
    vector<int> disFromSb = dijkstra(v + 2);

    int Answer = INF;
    for(int i=1; i<=v; i++){
        if(!isHouse[i]) continue;
        if(disFromMc[i] > x) continue;
        if(disFromSb[i] > y) continue;

        Answer = min(Answer, disFromMc[i] + disFromSb[i]);
    }

    cout << (Answer == INF ? -1 : Answer);

    return 0;
}

#include <bits/stdc++.h>
#define MAX_V 100
#define INF 1000000

using namespace std;

int v, m, jh, sh;
vector<pair<int, int>> g[MAX_V];

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

    cin >> v >> m;

    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    cin >> jh >> sh;

    vector<int> disFromJh = dijkstra(jh);
    vector<int> disFromSh = dijkstra(sh);

    int minT = 2 * INF;
    for(int i=1; i<=v; i++){
        if(i == jh || i == sh) continue;
        minT = min(minT, disFromJh[i] + disFromSh[i]);
    }

    int Answer = -1, minJh = INF;
    for(int i=1; i<=v; i++){
        if(i == jh || i == sh) continue;
        if(disFromJh[i] + disFromSh[i] == minT && disFromJh[i] <= disFromSh[i]){
            if(minJh > disFromJh[i]){
                minJh = disFromJh[i];
                Answer = i;
            }
        }
    }

    cout << Answer;

    return 0;
}

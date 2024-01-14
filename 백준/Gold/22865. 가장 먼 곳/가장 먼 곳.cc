#include <bits/stdc++.h>
#define MAX_N 100000
#define INF 1000000000

using namespace std;

vector<vector<pair<int, int>>> g(MAX_N + 1);

vector<int> dijkstra(int n, int start){
    priority_queue<pair<int, int>> q;
    vector<int> dis(n + 1, INF);

    dis[start] = 0;
    q.push({0, start});

    while(!q.empty()){
        int currNode = q.top().second;
        int currDis = -q.top().first;
        q.pop();

        if(dis[currNode] < currDis) continue;

        for(int i=0; i<g[currNode].size(); i++){
            int nxtNode = g[currNode][i].first;
            int nxtDis = currDis + g[currNode][i].second;

            if(nxtDis < dis[nxtNode]){
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

    int n, m, a, b, c;
    cin >> n >> a >> b >> c >> m;

    int d, e, l;
    for(int i=0; i<m; i++){
        cin >> d >> e >> l;
        g[d].push_back({e, l});
        g[e].push_back({d, l});
    }

    vector<int> disFromA = dijkstra(n, a);
    vector<int> disFromB = dijkstra(n, b);
    vector<int> disFromC = dijkstra(n, c);

    int maxValue = -1, Answer = -1;
    for(int i=1; i<=n; i++){
        if(i == a || i == b || i == c) continue;

        int minDis = min(disFromA[i], min(disFromB[i], disFromC[i]));
        if(minDis > maxValue){
            maxValue = minDis;
            Answer = i;
        }
    }

    cout << Answer;

    return 0;
}

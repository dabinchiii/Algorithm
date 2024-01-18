#include <bits/stdc++.h>
#define INF 10000000

using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>> g, int start){
    vector<int> dis(n + 1, INF);
    priority_queue<pair<int, int>> q;

    q.push({0, start});
    dis[start] = 0;

    while(!q.empty()){
        int currNode = q.top().second;
        int currDis = -q.top().first;
        q.pop();

        if(dis[currNode] < currDis) continue;

        for(pair<int, int> x : g[currNode]){
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

void solve(){
    int n, d, c;
    cin >> n >> d >> c;

    vector<vector<pair<int, int>>> g(n + 1);

    int a, b, s;
    for(int i=0; i<d; i++){
        cin >> a >> b >> s;
        g[b].push_back({a, s});
    }

    vector<int> dis = dijkstra(n, g, c);

    int AnswerCnt = 0, AnswerT = -1;
    for(int x : dis){
        if(x == INF) continue;
        AnswerCnt++;
        AnswerT = max(AnswerT, x);
    }

    cout << AnswerCnt << ' ' << AnswerT << '\n';
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

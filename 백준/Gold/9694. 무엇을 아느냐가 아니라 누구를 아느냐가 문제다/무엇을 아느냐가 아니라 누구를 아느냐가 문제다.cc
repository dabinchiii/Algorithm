#include <bits/stdc++.h>
#define INF 400

using namespace std;

void solve(int test_case){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> g[m];

    int x, y, z;
    for(int i=0; i<n; i++){
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    priority_queue<pair<int, int>> q;
    vector<int> dis(m, INF);
    vector<int> prev(m, -1);

    q.push({0, 0});
    dis[0] = 0;

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
                prev[nxtX] = currX;
            }
        }
    }

    cout << "Case #" << test_case << ": ";
    if(dis[m - 1] == INF){
        cout << -1 << '\n';
        return;
    }

    vector<int> path;
    int curr = m - 1;
    while(curr != -1){
        path.push_back(curr);
        curr = prev[curr];
    }

    for(int i=path.size() - 1; i>=0; i--){
        cout << path[i] << ' ';
    }
    cout << endl;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        solve(t);
    }

    return 0;
}

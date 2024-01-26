#include <bits/stdc++.h>
#define INF 2000000

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> road(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> road[i][j];
            if(road[i][j] == -1) road[i][j] = INF;
        }
    }

    priority_queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> cost(m, vector<int>(n, INF));

    q.push({-road[0][0], {0, 0}});
    cost[0][0] = road[0][0];

    while(!q.empty()){
        int currX = q.top().second.first;
        int currY = q.top().second.second;
        int currCost = -q.top().first;
        q.pop();

        if(cost[currX][currY] < currCost) continue;

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX >= m) continue;
            if(nxtY < 0 || nxtY >= n) continue;
            if(road[nxtX][nxtY] == INF) continue;

            int nxtCost = currCost + road[nxtX][nxtY];

            if(cost[nxtX][nxtY] > nxtCost){
                cost[nxtX][nxtY] = nxtCost;
                q.push({-nxtCost, {nxtX, nxtY}});
            }
        }
    }

    cout << (cost[m - 1][n - 1] == INF ? -1 : cost[m - 1][n - 1]);

    return 0;
}

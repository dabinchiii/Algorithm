#include <bits/stdc++.h>
#define MAX_N 50
#define INF 2500

using namespace std;

int n;
vector<vector<int>> maze(MAX_N, vector<int>(MAX_N));
vector<vector<int>> dis(MAX_N, vector<int>(MAX_N, INF));

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve(){
    priority_queue<pair<int, pair<int, int>>> q;

    q.push({0, {0, 0}});
    dis[0][0] = 0;

    while(!q.empty()){
        int currX = q.top().second.first;
        int currY = q.top().second.second;
        int currDis = -q.top().first;
        q.pop();

        if(dis[currX][currY] < currDis) continue;

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= n) continue;

            int nxtDis = currDis + maze[nxtX][nxtY];

            if(dis[nxtX][nxtY] > nxtDis){
                dis[nxtX][nxtY] = nxtDis;
                q.push({-nxtDis, {nxtX, nxtY}});
            }
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            maze[i][j] = (str[j] == '1' ? 0 : 1);
        }
    }

    solve();

    cout << dis[n - 1][n - 1];

    return 0;
}

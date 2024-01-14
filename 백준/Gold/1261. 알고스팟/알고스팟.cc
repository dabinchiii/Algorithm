#include <bits/stdc++.h>
#define MAX 100
#define INF 10000

using namespace std;

int m, n;
vector<vector<int>> maze(MAX, vector<int>(MAX));
vector<vector<int>> dis(MAX, vector<int>(MAX, INF));

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y){
    queue<pair<int, int>> q;

    q.push({x, y});
    dis[x][y] = 0;

    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= m) continue;

            if(dis[currX][currY] + maze[currX][currY] < dis[nxtX][nxtY]){
                dis[nxtX][nxtY] = dis[currX][currY] + maze[currX][currY];
                q.push({nxtX, nxtY});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            maze[i][j] = str[j] - '0';
        }
    }

    bfs(0, 0);

    cout << dis[n - 1][m - 1];

    return 0;
}

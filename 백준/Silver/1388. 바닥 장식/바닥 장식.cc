#include <bits/stdc++.h>
#define MAX_N 50
#define MAX_M 50

using namespace std;

int n, m;
int f[MAX_N][MAX_M];
bool visited[2][MAX_N][MAX_M];
int ans;

int dx[] = {0, 1};
int dy[] = {1, 0};

void bfs(int x, int y, int kind){
    priority_queue<pair<int, int>> q;
    q.push({x, y});

    visited[kind][x][y] = true;

    while(!q.empty()){
        int currX = q.top().first;
        int currY = q.top().second;
        q.pop();

        int nxtX = currX + dx[kind];
        int nxtY = currY + dy[kind];

        if(nxtY >= m) continue;
        if(f[nxtX][nxtY] != kind) continue;

        visited[kind][nxtX][nxtY] = true;
        q.push({nxtX, nxtY});
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    string line;
    for(int i=0; i<n; i++){
        cin >> line;
        for(int j=0; j<m; j++){
            f[i][j] = (line[j] == '-' ? 0 : 1);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[0][i][j] && f[i][j] == 0){
                ans++;
                bfs(i, j, 0);
            }
            if(!visited[1][i][j] && f[i][j] == 1){
                ans++;
                bfs(i, j, 1);
            }
        }
    }

    cout << ans;

    return 0;
}

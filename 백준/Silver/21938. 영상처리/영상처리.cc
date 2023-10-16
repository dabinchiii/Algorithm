#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int n, m, t;
int screen[MAX][MAX];
bool visited[MAX][MAX];
int Answer;

// 상, 하, 좌, 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y){
    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int nxtX = x + dx[i];
        int nxtY = y + dy[i];

        if(nxtX < 0 || nxtX >= n) continue;
        if(nxtY < 0 || nxtY >= m) continue;
        if(screen[nxtX][nxtY] == 0) continue;
        if(visited[nxtX][nxtY]) continue;

        dfs(nxtX, nxtY);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int r, g, b;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> r >> g >> b;
            screen[i][j] = r + g + b;
        }
    }

    cin >> t;
    t *= 3;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            screen[i][j] = (screen[i][j] >= t ? 255 : 0);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(screen[i][j] == 255 && !visited[i][j]){
                Answer++;
                dfs(i, j);
            }
        }
    }

    cout << Answer;

    return 0;
}

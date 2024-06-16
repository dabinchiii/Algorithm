#include <bits/stdc++.h>

using namespace std;

int board[5][5];
int r, c;
bool visited[5][5];
bool ans;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int dis, int apple){
    if(dis == 3){
        if(apple >= 2) ans = true;
        return;
    }

    for(int i=0; i<4; i++){
        int nxtX = x + dx[i];
        int nxtY = y + dy[i];

        if(nxtX < 0 || nxtX >= 5) continue;
        if(nxtY < 0 || nxtY >= 5) continue;
        if(board[nxtX][nxtY] == -1) continue;
        if(visited[nxtX][nxtY]) continue;

        visited[nxtX][nxtY] = true;
        dfs(nxtX, nxtY, dis + 1, apple + board[nxtX][nxtY]);
        visited[nxtX][nxtY] = false;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> board[i][j];
        }
    }

    cin >> r >> c;

    visited[r][c] = true;
    dfs(r, c, 0, (board[r][c] == 1 ? 1 : 0));

    cout << (ans ? 1 : 0);

    return 0;
}

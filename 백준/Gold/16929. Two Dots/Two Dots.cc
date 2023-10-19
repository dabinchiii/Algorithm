#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> board(50, vector<char>(50));
vector<vector<bool>> visited(50, vector<bool>(50, false));
bool Answer;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int currX, int currY, int k, int prevX, int prevY){
    visited[currX][currY] = true;
    k++;

    for(int i=0; i<4; i++){
        int nxtX = currX + dx[i];
        int nxtY = currY + dy[i];

        if(nxtX < 0 || nxtX >= n) continue;
        if(nxtY < 0 || nxtY >= m) continue;
        if(board[nxtX][nxtY] != board[currX][currY]) continue;
        if(visited[nxtX][nxtY] && !(nxtX == prevX && nxtY == prevY) && k >= 4){
            Answer = true;
            return;
        }
        if(!visited[nxtX][nxtY]) dfs(nxtX, nxtY, k, currX, currY);
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                dfs(i, j, 0, i, j);
            }
        }
    }

    cout << (Answer ? "Yes" : "No");

    return 0;
}

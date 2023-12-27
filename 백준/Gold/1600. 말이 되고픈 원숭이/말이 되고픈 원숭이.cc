#include <bits/stdc++.h>
#define MAX_W 200
#define MAX_H 200
#define MAX_K 30

using namespace std;

struct pos{
    int x, y;
};
struct queueEle{
    struct pos p;
    int cntMove;
    int cntHorseMove;
};

int k, w, h;
bool board[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W][MAX_K];
int Answer = -1;

struct pos d1[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
struct pos d2[] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

void solve(){
    queue<struct queueEle> q;
    q.push({{0, 0}, 0, 0});
    visited[0][0][0] = true;

    while(!q.empty()){
        int currX = q.front().p.x;
        int currY = q.front().p.y;
        int currMove = q.front().cntMove;
        int currHorseMove = q.front().cntHorseMove;
        q.pop();

        if(currX == h - 1 && currY == w - 1){
            Answer = currMove;
            break;
        }

        for(int i=0; i<4; i++){
            int nxtX = currX + d1[i].x;
            int nxtY = currY + d1[i].y;

            if(nxtX < 0 || nxtX >= h) continue;
            if(nxtY < 0 || nxtY >= w) continue;
            if(board[nxtX][nxtY]) continue;
            if(visited[nxtX][nxtY][currHorseMove]) continue;

            visited[nxtX][nxtY][currHorseMove] = true;
            q.push({{nxtX, nxtY}, currMove + 1, currHorseMove});
        }

        if(currHorseMove == k) continue;
        for(int i=0; i<8; i++){
            int nxtX = currX + d2[i].x;
            int nxtY = currY + d2[i].y;
            int nxtHorseMove = currHorseMove + 1;

            if(nxtX < 0 || nxtX >= h) continue;
            if(nxtY < 0 || nxtY >= w) continue;
            if(board[nxtX][nxtY]) continue;
            if(visited[nxtX][nxtY][nxtHorseMove]) continue;

            visited[nxtX][nxtY][nxtHorseMove] = true;
            q.push({{nxtX, nxtY}, currMove + 1, nxtHorseMove});
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> w >> h;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> board[i][j];
        }
    }

    solve();

    cout << Answer;

    return 0;
}

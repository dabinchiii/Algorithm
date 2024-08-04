#include <bits/stdc++.h>
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

using namespace std;

int n, m, x, y, k;
int board[20][20];
int dice[7];
int top, r, up;
int currX, currY;

// 1: 동, 2: 서, 3: 남, 4: 북
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void adjustDice(int comm){
    if(comm == EAST){
        swap(top, r);
        top = 7 - top;
    }
    else if(comm == WEST){
        swap(top, r);
        r = 7 - r;
    }
    else if(comm == NORTH){
        swap(top, up);
        top = 7 - top;
    }
    else if(comm == SOUTH){
        swap(top, up);
        up = 7 - up;
    }

    return;
}

void rollTheDice(int comm){
    int nxtX = currX + dx[comm];
    int nxtY = currY + dy[comm];

    if(nxtX < 0 || nxtX >= n) return;
    if(nxtY < 0 || nxtY >= m) return;

    adjustDice(comm);

    if(board[nxtX][nxtY] == 0){
        board[nxtX][nxtY] = dice[7 - top];
    }
    else{
        dice[7 - top] = board[nxtX][nxtY];
        board[nxtX][nxtY] = 0;
    }

    currX = nxtX;
    currY = nxtY;

    cout << dice[top] << '\n';

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x >> y >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    top = 1;
    r = 3;
    up = 2;

    currX = x;
    currY = y;

    int comm;
    for(int i=0; i<k; i++){
        cin >> comm;
        rollTheDice(comm);
    }

    return 0;
}

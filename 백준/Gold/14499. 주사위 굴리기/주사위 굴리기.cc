#include <bits/stdc++.h>
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

using namespace std;

int n, m, x, y, k;
int board[20][20];
int dice[7];
int top, bottom, r, l, up, down;
int currX, currY;

// 1: 동, 2: 서, 3: 남, 4: 북
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void adjustDice(int comm){
    if(comm == EAST){
        int tmp = top;
        top = l;
        l = bottom;
        bottom = r;
        r = tmp;
    }
    else if(comm == WEST){
        int tmp = top;
        top = r;
        r = bottom;
        bottom = l;
        l = tmp;
    }
    else if(comm == NORTH){
        int tmp = top;
        top = down;
        down = bottom;
        bottom = up;
        up = tmp;
    }
    else if(comm == SOUTH){
        int tmp = top;
        top = up;
        up = bottom;
        bottom = down;
        down = tmp;
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
        board[nxtX][nxtY] = dice[bottom];
    }
    else{
        dice[bottom] = board[nxtX][nxtY];
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
    bottom = 6;
    r = 3;
    l = 4;
    up = 2;
    down = 5;

    currX = x;
    currY = y;

    int comm;
    for(int i=0; i<k; i++){
        cin >> comm;
        rollTheDice(comm);
    }

    return 0;
}

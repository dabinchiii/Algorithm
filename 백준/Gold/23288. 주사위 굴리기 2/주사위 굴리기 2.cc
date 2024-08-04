#include <bits/stdc++.h>
#define EAST 1
#define WEST 2
#define SOUTH 3
#define NORTH 4

using namespace std;

int n, m, k;
int board[20][20];
int currX, currY;
int dir;
int dice[7];
int top, r, up;
int score;

// 1: 동, 2: 서, 3: 남, 4: 북
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};

// 반대방향: 동->서, 서->동, 남->북, 북->남
int opp[] = {0, WEST, EAST, NORTH, SOUTH};

// 시계방향90도: 동->남, 서->북, 남->서, 북->동
int clockwise[] = {0, SOUTH, NORTH, WEST, EAST};
// 반시계방향90도: 동->북, 서->남, 남->동, 북->서
int cclockwise[] = {0, NORTH, SOUTH, EAST, WEST};

void adjustDice(){
    if(dir == EAST){
        swap(top, r);
        top = 7 - top;
    }
    else if(dir == WEST){
        swap(top, r);
        r = 7 - r;
    }
    else if(dir == SOUTH){
        swap(top, up);
        up = 7 - up;
    }
    else if(dir == NORTH){
        swap(top, up);
        top = 7 - top;
    }

    return;
}

int bfs(int x, int y, int b){
    int c = 1;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        for(int i=1; i<=4; i++){
            int nxtX = curr.first + dx[i];
            int nxtY = curr.second + dy[i];

            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= m) continue;
            if(visited[nxtX][nxtY]) continue;
            if(board[nxtX][nxtY] != b) continue;

            c++;
            visited[nxtX][nxtY] = true;
            q.push({nxtX, nxtY});
        }
    }

    return c;
}

void rollTheDice(){
    int nxtX = currX + dx[dir];
    int nxtY = currY + dy[dir];

    if(nxtX < 0 || nxtX >= n || nxtY < 0 || nxtY >= m){
        dir = opp[dir];
        return;
    }

    k--;

    currX = nxtX;
    currY = nxtY;
    adjustDice();

    int a = dice[7 - top];
    int b = board[currX][currY];
    int c = bfs(currX, currY, b);

    score += b * c;

    if(a > b) dir = clockwise[dir];
    else if(a < b) dir = cclockwise[dir];

    return;
}

void init(){
    currX = currY = 0;

    for(int i=1; i<=6; i++){
        dice[i] = i;
    }

    top = 1;
    r = 3;
    up = 2;

    dir = EAST;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    init();
    while(k){
        rollTheDice();
    }

    cout << score;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef struct fish{
    int x, y;
    int d;
    bool isDead;
}fish;

vector<vector<int>> board(4, vector<int>(4));
vector<fish> fishInfo(17);
int ans;

int sharkX, sharkY, sharkD;

// x, ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

int ccw45[] = {0, 2, 3, 4, 5, 6, 7, 8, 1};

bool isInRange(int x, int y){
    if(x < 0 || x >= 4) return false;
    if(y < 0 || y >= 4) return false;
    return true;
}

void moveAllFish(){
    for(int i=1; i<=16; i++){
        if(fishInfo[i].isDead) continue;

        int currX = fishInfo[i].x;
        int currY = fishInfo[i].y;
        int currD = fishInfo[i].d;

        int nxtX = currX + dx[currD];
        int nxtY = currY + dy[currD];

        bool blocked = false;
        while(!isInRange(nxtX, nxtY) || (nxtX == sharkX && nxtY == sharkY)){
            currD = ccw45[currD];

            if(currD == fishInfo[i].d){
                blocked = true;
                break;
            }

            nxtX = currX + dx[currD];
            nxtY = currY + dy[currD];
        }

        if(blocked) continue;

        int tmp = board[nxtX][nxtY];

        swap(board[currX][currY], board[nxtX][nxtY]);

        fishInfo[i].x = nxtX;
        fishInfo[i].y = nxtY;
        fishInfo[i].d = currD;

        fishInfo[tmp].x = currX;
        fishInfo[tmp].y = currY;
    }

    return;
}

int eatFish(int x, int y){
    sharkX = x;
    sharkY = y;
    sharkD = fishInfo[board[x][y]].d;

    int num = board[x][y];

    fishInfo[board[x][y]].isDead = true;

    return num;
}

bool isSharkBlocked(){
    int nxtX = sharkX + dx[sharkD];
    int nxtY = sharkY + dy[sharkD];

    if(nxtX < 0 || nxtX >= 4) return true;
    if(nxtY < 0 || nxtY >= 4) return true;

    return false;
}

void bt(int x, int y, int currMax){
    vector<vector<int>> tmpBoard = board;
    vector<fish> tmpFishInfo = fishInfo;
    int tmpSharkX = sharkX;
    int tmpSharkY = sharkY;
    int tmpSharkD = sharkD;

    int num = eatFish(x, y);

    currMax += num;
    ans = max(ans, currMax);

    moveAllFish();

    if(isSharkBlocked()){
        board = tmpBoard;
        fishInfo = tmpFishInfo;
        sharkX = tmpSharkX;
        sharkY = tmpSharkY;
        sharkD = tmpSharkD;

        return;
    }

    int nxtX = sharkX;
    int nxtY = sharkY;

    while(true){
        nxtX += dx[sharkD];
        nxtY += dy[sharkD];

        if(!isInRange(nxtX, nxtY)) break;
        if(fishInfo[board[nxtX][nxtY]].isDead) continue;

        bt(nxtX, nxtY, currMax);
    }

    board = tmpBoard;
    fishInfo = tmpFishInfo;
    sharkX = tmpSharkX;
    sharkY = tmpSharkY;
    sharkD = tmpSharkD;

    return;
}

void solve(){
    bt(0, 0, 0);

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> a >> b;

            board[i][j] = a;
            fishInfo[a] = {i, j, b, false};
        }
    }

    solve();

    cout << ans;

    return 0;
}

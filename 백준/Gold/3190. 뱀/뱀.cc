#include <bits/stdc++.h>

#define EAST 0
#define WEST 1
#define SOUTH 2
#define NORTH 3

#define BLANK -1
#define APPLE 777

using namespace std;

int n, k;
int l;
int board[102][102];
pair<int, char> comm[100];
int currHX, currHY, currTX, currTY;
int ans;

// 동서남북
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 반시계방향: 동->북, 서->남, 남->동, 북->서
int ccw[] = {3, 2, 0, 1};
// 시계방향: 동->남, 서->북, 남->서, 북->동
int cw[] = {2, 3, 1, 0};

bool isWall(int x, int y){
    if(x <= 0 || x > n) return true;
    if(y <= 0 || y > n) return true;
    return false;
}
bool isBody(int x, int y){
    int curr = board[x][y];
    if(curr == EAST) return true;
    if(curr == WEST) return true;
    if(curr == SOUTH) return true;
    if(curr == NORTH) return true;
    return false;
}

bool goForward(int t){
    int currD = board[currHX][currHY];
    int nxtX = currHX + dx[currD];
    int nxtY = currHY + dy[currD];

    if(isWall(nxtX, nxtY)) return false;
    if(isBody(nxtX, nxtY)) return false;

    currHX = nxtX;
    currHY = nxtY;

    if(board[currHX][currHY] != APPLE){
        int tmpX = currTX;
        int tmpY = currTY;

        currTX = tmpX + dx[board[tmpX][tmpY]];
        currTY = tmpY + dy[board[tmpX][tmpY]];
        board[tmpX][tmpY] = BLANK;
    }

    board[currHX][currHY] = currD;

    return true;
}

void solve(){
    int t = 0, idx = 0;
    while(1){
        if(t == comm[idx].first){
            int currD, nxtD;
            currD = board[currHX][currHY];
            if(comm[idx].second == 'L'){
                nxtD = ccw[currD];
            }
            else{
                nxtD = cw[currD];
            }
            board[currHX][currHY] = nxtD;

            idx++;
        }

        if(!goForward(t++)) break;
    }
    ans = t;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            board[i][j] = BLANK;
        }
    }

    int x, y;
    for(int i=0; i<k; i++){
        cin >> x >> y;
        board[x][y] = APPLE;
    }

    cin >> l;

    for(int i=0; i<l; i++){
        cin >> comm[i].first >> comm[i].second;
    }

    currHX = currTX = 1;
    currHY = currTY = 1;
    board[currHX][currHY] = EAST;

    solve();

    cout << ans;

    return 0;
}

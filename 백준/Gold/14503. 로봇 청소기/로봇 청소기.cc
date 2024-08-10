#include <bits/stdc++.h>

#define WALL 1
#define BLANK_DIRTY 0
#define BLANK_CLEAN -1

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int n, m;
int r, c, d;
int room[50][50];
int currX, currY, currD;
int ans;

// 0123 => 북동남서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// 반시계방향: 북->서, 동->북, 남->동, 서->남
int ccw[] = {3, 0, 1, 2};
// 반대방향: 북->남, 동->서, 남->북, 서->동
int opp[] = {2, 3, 0, 1};

bool checkRange(int x, int y){
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= m) return false;
    return true;
}

bool moveCleaner(){
    // 1. 현재 칸이 아직 청소되지 않은 경우
    if(room[currX][currY] == BLANK_DIRTY){
        room[currX][currY] = BLANK_CLEAN;
        ans++;
    }

    // 주변 4칸 탐색
    bool dirtyBlank = false;
    for(int i=0; i<4; i++){
        int nxtX = currX + dx[i];
        int nxtY = currY + dy[i];

        if(!checkRange(nxtX, nxtY)) continue;
        if(room[nxtX][nxtY] != BLANK_DIRTY) continue;

        dirtyBlank = true;
        break;
    }

    if(!dirtyBlank){ // 청소되지 않은 빈 칸이 없는 경우
        int backX = currX + dx[opp[currD]];
        int backY = currY + dy[opp[currD]];

        if(checkRange(backX, backY) && room[backX][backY] != WALL){
            currX = backX;
            currY = backY;
            return true;
        }
        else{
            return false;
        }
    }
    else{ // 청소되지 않은 빈 칸이 있는 경우
        currD = ccw[currD];

        int nxtX = currX + dx[currD];
        int nxtY = currY + dy[currD];

        if(checkRange(nxtX, nxtY) && room[nxtX][nxtY] == BLANK_DIRTY){
            currX = nxtX;
            currY = nxtY;
        }

        return true;
    }

}

void solve(){
    currX = r;
    currY = c;
    currD = d;

    while(moveCleaner()) {}

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> room[i][j];
        }
    }

    solve();

    cout << ans;

    return 0;
}

#include <iostream>
#include <vector>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

// 상하좌우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 시계 방향 (상하좌우 => 우좌상하)
int cw[] = {3, 2, 0, 1};
// 반시계 방향 (상하좌우 => 좌우하상)
int ccw[] = {2, 3, 1, 0};

int r, c, t;
vector<vector<int>> board(50, vector<int>(50));
vector<pair<int, int>> purifier;
int ans;

bool isValid(int x, int y){
    if(x < 0 || x >= r) return false;
    if(y < 0 || y >= c) return false;
    return true;
}
bool isPurifier(int x, int y){
    if(y != 0) return false;
    
    if(x == purifier[0].first) return true;
    if(x == purifier[1].first) return true;
    
    return false;
}

void spreadDust(){
    vector<vector<int>> newBoard(board);
    
    for(int x=0; x<r; x++){
        for(int y=0; y<c; y++){
            if(isPurifier(x, y)) continue;
            
            for(int d=0; d<4; d++){
                int nxtX = x + dx[d];
                int nxtY = y + dy[d];
                
                if(!isValid(nxtX, nxtY) || isPurifier(nxtX, nxtY)) continue;
                
                int dust = board[x][y] / 5;
                newBoard[nxtX][nxtY] += dust;
                newBoard[x][y] -= dust;
            }
        }
    }
    
    board = newBoard;
    
    return;
}

void purifyUp(){
    int limitX = purifier[0].first;
    
    int currD = UP;
    int currX = purifier[0].first + dx[currD];
    int currY = purifier[0].second + dy[currD];
    
    int nxtX, nxtY;
    while(!isPurifier(currX, currY)){
        nxtX = currX + dx[currD];
        nxtY = currY + dy[currD];
        
        if(!isValid(nxtX, nxtY) || (currD == DOWN && nxtX > limitX)){
            currD = cw[currD];
            
            nxtX = currX + dx[currD];
            nxtY = currY + dy[currD];
        }
        
        board[currX][currY] = board[nxtX][nxtY];
        
        currX = nxtX;
        currY = nxtY;
    }
    
    return;
}
void purifyDown(){
    int limitX = purifier[1].first;
    
    int currD = DOWN;
    int currX = purifier[1].first + dx[currD];
    int currY = purifier[1].second + dy[currD];
    
    int nxtX, nxtY;
    while(!isPurifier(currX, currY)){
        nxtX = currX + dx[currD];
        nxtY = currY + dy[currD];
        
        if(!isValid(nxtX, nxtY) || (currD == UP && nxtX < limitX)){
            currD = ccw[currD];
            
            nxtX = currX + dx[currD];
            nxtY = currY + dy[currD];
        }
        
        board[currX][currY] = board[nxtX][nxtY];
        
        currX = nxtX;
        currY = nxtY;
    }
    
    return;
}

void solve(){
    int currT = 0;
    
    while(currT < t){
        spreadDust();
        
        purifyUp();
        purifyDown();
        
        currT++;
    }
    
    for(int x=0; x<r; x++){
        for(int y=0; y<c; y++){
            ans += board[x][y];
        }
    }
    
    return;
}

int main(){
    cin >> r >> c >> t;
    
    for(int x=0; x<r; x++){
        for(int y=0; y<c; y++){
            cin >> board[x][y];
            
            if(board[x][y] == -1){
                purifier.push_back({x, y});
                board[x][y] = 0;
            }
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

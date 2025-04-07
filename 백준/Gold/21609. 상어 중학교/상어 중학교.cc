#include <iostream>
#include <vector>
#include <queue>

#define BLANK -2

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
vector<vector<int>> board(20, vector<int>(20));
int ans;

bool isValid(int x, int y){
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= n) return false;
    return true;
}

pair<int, int> cntGroup(int x, int y, vector<vector<bool>> &visited){
    int cnt = 0, cntR = 0;
    int color = board[x][y];
    
    queue<pair<int, int>> q;
    
    q.push({x, y});
    visited[x][y] = true;
    cnt++;
    
    vector<pair<int, int>> rainbow;
    
    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        
        for(int d=0; d<4; d++){
            int nxtX = currX + dx[d];
            int nxtY = currY + dy[d];
            
            if(!isValid(nxtX, nxtY)) continue;
            if(visited[nxtX][nxtY]) continue;
            if(board[nxtX][nxtY] < 0) continue;
            if(board[nxtX][nxtY] != 0 && board[nxtX][nxtY] != color) continue;
            
            visited[nxtX][nxtY] = true;
            q.push({nxtX, nxtY});
            if(board[nxtX][nxtY] == 0) rainbow.push_back({nxtX, nxtY});
            
            cnt++;
            if(board[nxtX][nxtY] == 0) cntR++;
        }
        
    }
    
    for(pair<int, int> curr : rainbow){
        visited[curr.first][curr.second] = false;
    }
    
    return {cnt, cntR};
}
pair<int, int> findLargestGroup(){
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    int maxCnt = -1, maxCntR = -1;
    int resX = -1, resY = -1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]) continue;
            if(board[i][j] <= 0) continue; // 일반블럭이 아님
            
            pair<int, int> res = cntGroup(i, j, visited);
            int cnt = res.first;
            int cntR = res.second;
            
            if(cnt < 2) continue;
            if(cnt < maxCnt) continue;
            if(cnt == maxCnt && cntR < maxCntR) continue;
            
            maxCnt = cnt;
            maxCntR = cntR;
            resX = i;
            resY = j;
            
        }
    }
    
    return {resX, resY};
}
void deleteGroup(int x, int y){
    int cnt = 0;
    int color = board[x][y];
    
    queue<pair<int, int>> q;
    
    q.push({x, y});
    board[x][y] = BLANK;
    cnt++;
    
    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        
        for(int d=0; d<4; d++){
            int nxtX = currX + dx[d];
            int nxtY = currY + dy[d];
            
            if(!isValid(nxtX, nxtY)) continue;
            if(board[nxtX][nxtY] != 0 && board[nxtX][nxtY] != color) continue;

            board[nxtX][nxtY] = BLANK;
            q.push({nxtX, nxtY});
            cnt++;
        }
    }
    
    ans += cnt * cnt;
    
    return;
}
void gravity(){
    queue<int> q;
    
    for(int i=0; i<n; i++){ // 열
        for(int j=n - 1; j>=0; j--){ // 행
            if(board[j][i] < 0) continue;
            
            int currX = j, nxtX = j + 1;
            while(nxtX < n && board[nxtX][i] == BLANK){
                swap(board[currX][i], board[nxtX][i]);
                currX = nxtX;
                nxtX = currX + 1;
            }
        }
    }
    
    return;
}

void rotate(){
    int tmp[n];
    
    for(int p=0; p<n / 2; p++){
        int len = n - p * 2;
        int startX, startY, endX, endY;
        startX = startY = p;
        endX = endY = p + len - 1;
        
        for(int i=0; i<len - 1; i++){
            tmp[i] = board[startX][startY + i];
        }
        for(int i=0; i<len - 1; i++){
            board[startX][startY + i] = board[startX + i][endY];
        }
        for(int i=0; i<len - 1; i++){
            board[startX + i][endY] = board[endX][endY - i];
        }
        for(int i=0; i<len - 1; i++){
            board[endX][endY - i] = board[endX - i][startY];
        }
        for(int i=0; i<len - 1; i++){
            board[endX - i][startY] = tmp[i];
        }
    }
    
    return;
}

void solve(){
    while(true){
        pair<int, int> target = findLargestGroup();
        if(target.first == -1) break;
        
        deleteGroup(target.first, target.second);
        
        gravity();
        rotate();
        gravity();
    }
    
    return;
}
int main(){
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

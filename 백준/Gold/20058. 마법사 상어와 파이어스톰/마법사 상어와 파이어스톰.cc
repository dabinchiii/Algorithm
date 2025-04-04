#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, n2, q;
vector<vector<int>> board(64, vector<int>(64));
int arrL[1000];
int ansSum, ansCnt;

bool visited[64][64];

int bfs(int startX, int startY){
    visited[startX][startY] = true;
    
    queue<pair<int, int>> q;
    q.push({startX, startY});
    
    int cnt = 1;
    
    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        
        for(int d=0; d<4; d++){
            int nxtX = currX + dx[d];
            int nxtY = currY + dy[d];
            
            if(nxtX < 0 || nxtX >= n2) continue;
            if(nxtY < 0 || nxtY >= n2) continue;
            if(visited[nxtX][nxtY]) continue;
            if(board[nxtX][nxtY] == 0) continue;
            
            visited[nxtX][nxtY] = true;
            q.push({nxtX, nxtY});
            cnt++;
        }
        
        
    }
    
    return cnt;
}

void meltIce(){
    vector<vector<int>> newBoard = board;
    
    for(int i=0; i<n2; i++){
        for(int j=0; j<n2; j++){
            if(board[i][j] == 0) continue;
            
            int cnt = 0;
            
            for(int d=0; d<4; d++){
                int nxtX = i + dx[d];
                int nxtY = j + dy[d];
                
                if(nxtX < 0 || nxtX >= n2) continue;
                if(nxtY < 0 || nxtY >= n2) continue;
                if(board[nxtX][nxtY] == 0) continue;
                
                cnt++;
            }
            
            if(cnt < 3) newBoard[i][j]--;
            
        }
    }
    
    board = newBoard;
    
    return;
}
void rotate(int startX, int startY, int l){
    int endX = startX + l - 1;
    int endY = startY + l - 1;
    
    int tmp[l - 1];
    
    for(int i=0; i<l-1; i++){
        tmp[i] = board[startX][startY + i];
    }
    
    for(int i=0; i<l-1; i++){
        board[startX][startY + i] = board[endX - i][startY];
    }
    for(int i=0; i<l-1; i++){
        board[endX - i][startY] = board[endX][endY - i];
    }
    for(int i=0; i<l-1; i++){
        board[endX][endY - i] = board[startX + i][endY];
    }
    for(int i=0; i<l-1; i++){
        board[startX + i][endY] = tmp[i];
    }
    
    return;
}
void firetornado(int l){
    int len = pow(2, l);
    
    for(int i=0; i<n2; i+=len){
        for(int j=0; j<n2; j+=len){
            
            for(int k=0; k<len / 2; k++){
                rotate(i + k, j + k, len - 2 * k);
            }
        }
    }
    
    meltIce();
    
    return;
}
void solve(){
    for(int i=0; i<q; i++){
        firetornado(arrL[i]);
    }
    
    
    for(int i=0; i<n2; i++){
        for(int j=0; j<n2; j++){
            ansSum += board[i][j];
            
            if(!visited[i][j] && board[i][j] != 0){
                ansCnt = max(ansCnt, bfs(i, j));
            }
        }
    }
    
    return;
}

int main(){
    cin >> n >> q;
    
    n2 = pow(2, n);
    
    for(int i=0; i<n2; i++){
        for(int j=0; j<n2; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i=0; i<q; i++){
        cin >> arrL[i];
    }
    
    solve();
    
    cout << ansSum << endl << ansCnt;
    
    return 0;
}

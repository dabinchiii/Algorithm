#include <iostream>
#include <vector>
#include <queue>

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

using namespace std;

int n;
vector<vector<int>> initBoard(20, vector<int>(20));
vector<vector<int>> board(20, vector<int>(20, 0));
int ans;


// 상하좌우
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
// ======================
void slideRight();
void slideLeft();
void slideUp();
void slideDown();

void mergeRight();
void mergeLeft();
void mergeUp();
void mergeDown();

int findMax(){
    int maxValue = -1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 0) continue;
            maxValue = max(maxValue, board[i][j]);
        }
    }
    
    return maxValue;
}

void move(int d, int currCnt, vector<vector<int>> currBoard){
    auto backup = board;
    board = currBoard;
    
    if(currCnt == 5){
        ans = max(ans, findMax());
        
        board = backup;
        
        return;
    }
    
    if(d == UP){
        slideUp();
        mergeUp();
        slideUp();
    }
    else if(d == DOWN){
        slideDown();
        mergeDown();
        slideDown();
    }
    else if(d == LEFT){
        slideLeft();
        mergeLeft();
        slideLeft();
    }
    else if(d == RIGHT){
        slideRight();
        mergeRight();
        slideRight();
    }
    
    
    
    for(int i=0; i<4; i++){
        move(i, currCnt + 1, board);
    }
    
    board = backup;
    
    return;
}

void solve(){
    // ans: 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값
    
    for(int i=0; i<4; i++){
        move(i, 0, initBoard);
    }
    
    return;
}

int main(){
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    initBoard = board;
    
    ans = -1;
    
    solve();
    
//    moveD(0);
//    
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            cout << board[i][j] << ' ';
//        }
//        cout << endl;
//    }
    
    cout << ans;
    
    return 0;
}

void slideRight(){
    vector<vector<int>> newBoard(n, vector<int>(n, 0));
    
    for(int i=0; i<n; i++){
        queue<int> q;
        
        for(int j=n - 1; j>=0; j--){
            if(board[i][j] == 0) continue;
            q.push(board[i][j]);
        }
        
        int k = 0;
        while(!q.empty()){
            newBoard[i][n - 1 - k] = q.front();
            k++;
            q.pop();
        }
    }
    
    board = newBoard;
    
    return;
}
void slideLeft(){
    vector<vector<int>> newBoard(n, vector<int>(n, 0));
    
    for(int i=0; i<n; i++){
        queue<int> q;
        
        for(int j=0; j<n; j++){
            if(board[i][j] == 0) continue;
            q.push(board[i][j]);
        }
        
        int k = 0;
        while(!q.empty()){
            newBoard[i][k] = q.front();
            k++;
            q.pop();
        }
    }
    
    board = newBoard;
    
    return;
}
void slideUp(){
    vector<vector<int>> newBoard(n, vector<int>(n, 0));
    
    for(int i=0; i<n; i++){
        queue<int> q;
        
        for(int j=0; j<n; j++){
            if(board[j][i] == 0) continue;
            q.push(board[j][i]);
        }
        
        int k = 0;
        while(!q.empty()){
            newBoard[k][i] = q.front();
            k++;
            q.pop();
        }
    }
    
    board = newBoard;
    
    return;
}
void slideDown(){
    vector<vector<int>> newBoard(n, vector<int>(n, 0));
    
    for(int i=0; i<n; i++){
        queue<int> q;
        
        for(int j=n - 1; j>=0; j--){
            if(board[j][i] == 0) continue;
            q.push(board[j][i]);
        }
        
        int k = 0;
        while(!q.empty()){
            newBoard[n - 1 - k][i] = q.front();
            k++;
            q.pop();
        }
    }
    
    board = newBoard;
    
    return;
}

void mergeRight(){
    for(int i=0; i<n; i++){
        for(int j=n - 1; j>=1; j--){
            if(board[i][j] == 0) continue;
            if(board[i][j] != board[i][j-1]) continue;
            
            board[i][j] *= 2;
            board[i][j - 1] = 0;
        }
    }
    
    return;
}
void mergeLeft(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n - 1; j++){
            if(board[i][j] == 0) continue;
            if(board[i][j] != board[i][j+1]) continue;
            
            board[i][j] *= 2;
            board[i][j + 1] = 0;
        }
    }
    
    return;
}
void mergeUp(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n - 1; j++){
            if(board[j][i] == 0) continue;
            if(board[j][i] != board[j + 1][i]) continue;
            
            board[j][i] *= 2;
            board[j + 1][i] = 0;
        }
    }
    
    return;
}
void mergeDown(){
    for(int i=0; i<n; i++){
        for(int j=n - 1; j>= 1; j--){
            if(board[j][i] == 0) continue;
            if(board[j][i] != board[j - 1][i]) continue;
            
            board[j][i] *= 2;
            board[j - 1][i] = 0;
        }
    }
    
    return;
}

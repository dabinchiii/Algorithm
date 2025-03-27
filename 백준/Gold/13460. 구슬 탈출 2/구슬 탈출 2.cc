#include <iostream>

using namespace std;

typedef struct loc{
    int x, y;
}loc;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
char board[10][10];
loc red, blue, whole;
int ans;

bool operator==(loc a, loc b){
    return (a.x == b.x && a.y == b.y);
}

void tiltRed(int d){
    char backup = board[blue.x][blue.y];
    if(board[blue.x][blue.y] != 'O') board[blue.x][blue.y] = 'B';
    
    if(d == 0 || d == 1){ // up or down
        int nxtX = red.x + dx[d];
        
        while(board[nxtX][red.y] == '.'){
            nxtX += dx[d];
        }
        
        red.x = (board[nxtX][red.y] == 'O' ? nxtX : nxtX - dx[d]);
    }
    else{ // left or right
        int nxtY = red.y + dy[d];
        
        while(board[red.x][nxtY] == '.'){
            nxtY += dy[d];
        }
        
        red.y = (board[red.x][nxtY] == 'O' ? nxtY : nxtY - dy[d]);
    }
    
    board[blue.x][blue.y] = backup;
    
    return;
}

void tiltBlue(int d){
    char backup = board[red.x][red.y];
    if(board[red.x][red.y] != 'O') board[red.x][red.y] = 'R';
    
    if(d == 0 || d == 1){
        int nxtX = blue.x + dx[d];
        
        while(board[nxtX][blue.y] == '.'){
            nxtX += dx[d];
        }
        
        blue.x = (board[nxtX][blue.y] == 'O' ? nxtX : nxtX - dx[d]);
    }
    else{
        int nxtY = blue.y + dy[d];
        
        while(board[blue.x][nxtY] == '.'){
            nxtY += dy[d];
        }
        
        blue.y = (board[blue.x][nxtY] == 'O' ? nxtY : nxtY - dy[d]);
    }
    
    board[red.x][red.y] = backup;
    
    return;
}

int tilt(int d){
    bool redFirst = false;
    if(d == 0){
        if(red.x < blue.x) redFirst = true;
    }
    else if(d == 1){
        if(red.x > blue.x) redFirst = true;
    }
    else if(d == 2){
        if(red.y < blue.y) redFirst = true;
    }
    else if(d == 3){
        if(red.y > blue.y) redFirst = true;
    }
    
    if(redFirst){
        tiltRed(d);
        tiltBlue(d);
    }
    else{
        tiltBlue(d);
        tiltRed(d);
    }
    
    if(blue == whole) return -1;
    if(red == whole) return 1;
    
//    if(blue.x == whole.x && blue.y == whole.y) return -1;
//    if(red.x == whole.x && red.y == whole.y) return 1;
    
    return 0;
}

void dfs(int cnt){
    if(cnt > 10) return;
    
    for(int d=0; d<4; d++){
        loc r = red, b = blue;
        
        int result = tilt(d);
        
        if(result == 1){
            ans = min(ans, cnt);
//            cout << cnt << "ok" << endl;
        }
        else if(result == -1){
        }
        else if(result == 0){
            dfs(cnt + 1);
        }
        red = r;
        blue = b;
    }
    
    
    return;
}

void solve(){
    ans = 999;
    
    dfs(1);
    
    if(ans == 999) ans = -1;
    
    return;
}

int main(){
    cin >> n >> m;
    
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        
        for(int j=0; j<m; j++){
            board[i][j] = str[j];
            
            if(board[i][j] == 'R'){
                red = {i, j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'B'){
                blue = {i, j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'O'){
                whole = {i, j};
            }
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

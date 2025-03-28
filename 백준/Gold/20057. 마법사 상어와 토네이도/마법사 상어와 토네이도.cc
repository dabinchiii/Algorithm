#include <iostream>

using namespace std;

typedef struct windNode{
    int dd;
    int dcw;
    double r;
}windNode;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 시계방향 (상하좌우 => 우좌상하)
int cw[] = {3, 2, 0, 1};

// 반시계방향 (상하좌우 => 좌우하상)
int ccw[] = {2, 3, 1, 0};

int n;
int board[499][499];
int totalSand;
int currX, currY, currD;
int ans;
bool done;

windNode w[9] = {
    {2, 0, 0.05},
    {1, 1, 0.10},
    {1, -1, 0.10},
    {0, 1, 0.07},
    {0, -1, 0.07},
    {0, 2, 0.02},
    {0, -2, 0.02},
    {-1, 1, 0.01},
    {-1, -1, 0.01}
};

bool isValid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}
void moveTornado(){
    
    int nxtX = currX + dx[currD];
    int nxtY = currY + dy[currD];
    
    if(!isValid(nxtX, nxtY)){
        done = true;
        return;
    }
    
    currX = nxtX;
    currY = nxtY;
    
    int a = board[currX][currY];
    board[currX][currY] = 0;
    
    int sum = 0; // a에서 손실된 모래양
    for(int i=0; i<9; i++){
        windNode curr = w[i];
        
        int x = currX, y = currY;
        x += curr.dd * dx[currD];
        y += curr.dd * dy[currD];
        
        x += curr.dcw * dx[cw[currD]];
        y += curr.dcw * dy[cw[currD]];
        
        int sand = static_cast<double>(a) * curr.r;
       
        if(isValid(x, y)){
            board[x][y] += sand;
        }
        
        sum += sand;
        
    }
    a -= sum;
    
    int ax = currX + dx[currD];
    int ay = currY + dy[currD];
    
    if(!isValid(ax, ay)) return;
    
    board[ax][ay] += a;
    
    return;
}

void solve(){
    int l = 1;
    
    currX = currY = n / 2;
    currD = 2; // left
    
    while(!done){
        for(int i=0; i<2 && !done; i++){
            for(int j=0; j<l; j++){
                moveTornado();
            }
            currD = ccw[currD];
        }
        l++;
    }
    
    int leftSand = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            leftSand += board[i][j];
        }
    }
    
    ans = totalSand - leftSand;
    
    return;
}

int main(){
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            
            totalSand += board[i][j];
        }
    }
    
    solve();
    

    cout << ans;
    
    return 0;
}

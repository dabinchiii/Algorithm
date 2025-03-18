#include <iostream>

using namespace std;

int n, m;
int board[8][500][500];
int ans;

// 테트로미노
int tdx[5][4] = {
    {0, 0, 0, 0},
    {0, 0, 1, 1},
    {0, 1, 2, 2},
    {0, 1, 1, 2},
    {0, 0, 0, 1},
};
int tdy[5][4] = {
    {0, 1, 2, 3},
    {0, 1, 0, 1},
    {0, 0, 0, 1},
    {0, 0, 1, 1},
    {0, 1, 2, 1},
};

int findMax(int bIdx, int tIdx){
    int xLimit = (bIdx < 4 ? n : m);
    int yLimit = (bIdx < 4 ? m : n);
    
    int maxValue = -1;
    
    for(int i=0; i<xLimit; i++){
        for(int j=0; j<yLimit; j++){
            
            int sum = 0;
            bool ok = true;
            
            for(int k=0; k<4; k++){
                int currX = i + tdx[tIdx][k];
                int currY = j + tdy[tIdx][k];
                
                if(currX < 0 || currX >= xLimit || currY < 0 || currY >= yLimit){
                    ok = false;
                    break;
                }
                
                sum += board[bIdx][currX][currY];
            }
            
            if(!ok) continue;
            
            maxValue = max(maxValue, sum);
        }
    }
    
    return maxValue;
}

void solve(){
    for(int i=0; i<8; i++){
        for(int j=0; j<5; j++){
            ans = max(ans, findMax(i, j));
        }
    }
    
    return;
}

int main(){
    cin >> n >> m;
    
    int num;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> num;
            
            board[0][i][j] = num;
            board[1][i][m - 1 - j] = num;
            board[2][n - 1 - i][j] = num;
            board[3][n - 1 - i][m - 1 - j] = num;
            
            board[4][j][i] = num;
            board[5][j][n - 1 - i] = num;
            board[6][m - 1 - j][i] = num;
            board[7][m - 1 - j][n - 1 - i] = num;
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

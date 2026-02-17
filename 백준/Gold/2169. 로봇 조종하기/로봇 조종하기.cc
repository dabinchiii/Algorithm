#include <iostream>
#include <algorithm>

#define MAX_N 1000
#define MAX_M 1000

#define NEG_INF -100000000

using namespace std;

int N, M;
int w[MAX_N][MAX_M], dp[MAX_N][MAX_M][3]; // [][][0]: from up, [][][1]: from left, [][][2]: from right
int ans;

void solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<3; k++){
                dp[i][j][k] = NEG_INF;
            }
        }
    }
    
    dp[0][0][0] = dp[0][0][1] = w[0][0];
    
    for(int c=1; c<M; c++) dp[0][c][1] = w[0][c] + dp[0][c - 1][1];
    
    for(int r=1; r<N; r++){
        
        dp[r][0][0] = w[r][0] + max(dp[r - 1][0][0], max(dp[r - 1][0][1], dp[r - 1][0][2]));
        
        for(int c=1; c<M; c++){
            dp[r][c][0] = w[r][c] + max(dp[r - 1][c][0], max(dp[r - 1][c][1], dp[r - 1][c][2]));
            dp[r][c][1] = w[r][c] + max(dp[r][c - 1][0], dp[r][c - 1][1]);
        }
        
        for(int c=M - 2; c>=0; c--){
            dp[r][c][2] = w[r][c] + max(dp[r][c + 1][0], dp[r][c + 1][2]);
        }
    }
    
    ans = max(dp[N - 1][M - 1][0], dp[N - 1][M - 1][1]);
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> w[i][j];
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

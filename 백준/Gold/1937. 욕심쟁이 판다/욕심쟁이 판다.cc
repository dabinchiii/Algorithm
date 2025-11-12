#include <iostream>
#include <algorithm>

#define MAX_N 500

using namespace std;

// 상하좌우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int N;
int board[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

bool check(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < N;
}

void dfs(int sr, int sc){
    for(int d=0; d<4; d++){
        int nr = sr + dr[d];
        int nc = sc + dc[d];
        
        if(!check(nr, nc)) continue;
        if(board[nr][nc] <= board[sr][sc]) continue;
        
        if(dp[nr][nc] == 0) dfs(nr, nc);
        
        dp[sr][sc] = max(dp[sr][sc], dp[nr][nc]);
    }
    
    dp[sr][sc] += 1; // 자기자신
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }
    
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dp[i][j] == 0) dfs(i, j);
            ans = max(ans, dp[i][j]);
        }
    }
    
    cout << ans;
    
    return 0;
}

#include <iostream>

using namespace std;

int n, m;
int t[501][501];
int ans;

int dp[501][501];

void solve(){
    for(int i=2; i<=n; i++){
        for(int j=1; j<=m; j++){
            int minT = 5000001;
            
            for(int k=1; k<=m; k++){
                if(j == k) continue; // 바로 이전 회차 무기
                
                minT = min(minT, dp[i - 1][k]);
            }
            
            dp[i][j] += minT;
        }
    }
    
    ans = 5000001;
    for(int i=1; i<=m; i++){
        ans = min(ans, dp[n][i]);
    }
    
    return;
}

int main(){
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> t[i][j];
            dp[i][j] = t[i][j];
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

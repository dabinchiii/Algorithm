#include <iostream>

#define MOD 9901

using namespace std;

int n;
int dp[100001][3]; // 0: ox, 1: xo, 2: xx
int ans;

void solve(){
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    
    for(int i=2; i<=n; i++){
        dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        
        for(int j=0; j<3; j++) dp[i][j] %= MOD;
    }
    
    ans = dp[n][0] + dp[n][1] + dp[n][2];
    ans %= MOD;
        
    return;
}

int main(){
    cin >> n;
    
    solve();
    cout << ans;
    
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int k;
int t[501], pSum[501];
int dp[501][501];
int ans;

void solve(){
//    for(int i=1; i<=k; i++) dp[i][i] = 0;
    
    for(int len=2; len<=k; len++){
        for(int i=1; i<=k; i++){
            int j = i + len - 1;
            
            if(j > k) break;
            
            dp[i][j] = 999999999;
            for(int m=i; m<j; m++){
                dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j] + (pSum[j] - pSum[i - 1]));
            }
        }
    }
    
    
    ans = dp[1][k];
    
    return;
}

int main(){
    int T;
    cin >> T;
    
    for(int test_case=1; test_case<=T; test_case++){
        cin >> k;
        
        for(int i=1; i<=k; i++){
            cin >> t[i];
            pSum[i] = pSum[i - 1] + t[i];
        }
        
        solve();
        
        cout << ans << endl;
    }
    
    return 0;
}

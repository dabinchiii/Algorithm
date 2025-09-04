#include <string>
#include <vector>

#define MAX_N 100000
#define MOD 10007

using namespace std;

int dp[2][MAX_N];


int solution(int n, vector<int> tops) {
    dp[0][0] = (tops[0] ? 3 : 2);
    dp[1][0] = 1;
    
    for(int i=1; i<n; i++){
        dp[0][i] = ((tops[i] ? 3 : 2) * dp[0][i - 1]) + (tops[i] ? 2 : 1) * dp[1][i - 1];
        dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
        
        dp[0][i] %= MOD;
        dp[1][i] %= MOD;
    }
    
    // for(int i=0; i<n; i++){
    //     printf("[%d] %d %d\n", i, dp[0][i], dp[1][i]);
    // }
    return (dp[0][n - 1] + dp[1][n - 1]) % MOD;
}
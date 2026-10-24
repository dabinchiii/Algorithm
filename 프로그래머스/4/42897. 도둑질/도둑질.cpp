#include <bits/stdc++.h>

#define MAX_N 1000000

using namespace std;

int N;
int dp[MAX_N + 1][2];

int solution(vector<int> money) {
    N = money.size();
    
    dp[1][0] = money[0];
    for(int i=2; i<=N; i++){
        dp[i][0] = money[i - 1] + max(dp[i - 2][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    
    int ans = max(dp[N][1], dp[N - 1][0]);
    
    dp[1][0] = 0;
    for(int i=2; i<=N; i++){
        dp[i][0] = money[i - 1] + max(dp[i - 2][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    
    ans = max(ans, max(dp[N][0], dp[N][1]));
    
    return ans;
}
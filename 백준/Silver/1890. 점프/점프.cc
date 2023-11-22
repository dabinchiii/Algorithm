#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = 1;

    int num;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> num;

            if(dp[i][j] == 0 || num == 0) continue;

            if(i + num < n) dp[i + num][j] += dp[i][j];
            if(j + num < n) dp[i][j + num] += dp[i][j];
        }
    }


    cout << dp[n-1][n-1];

    return 0;
}

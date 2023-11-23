#include <bits/stdc++.h>
#define MAX_N 1000000
#define MOD 1000000009

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> dp(MAX_N + 1);
    dp[0] = 1;

    for(int i=1; i<=MAX_N; i++){
        dp[i] = dp[i - 1];

        if(i - 2 < 0) continue;
        dp[i] += dp[i - 2];
        dp[i] %= MOD;

        if(i - 3 < 0) continue;
        dp[i] += dp[i - 3];
        dp[i] %= MOD;
    }

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}

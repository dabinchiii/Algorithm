#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> dp(101);
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for(int i=6; i<=100; i++){
        dp[i] = dp[i - 1] + dp[i - 5];
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

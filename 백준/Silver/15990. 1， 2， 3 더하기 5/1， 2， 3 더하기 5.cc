#include <bits/stdc++.h>
#define MAX_N 100000
#define MOD 1000000009

using namespace std;

long long dp[MAX_N+1][4]; // [][0]: 안 씀. 1, 2, 3이랑 [][1], [][2], [][3] 인덱스 맞추려고

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int n;
        cin >> n;

        dp[1][1] = 1;
        dp[2][2] = 1;
        dp[3][1] = 1;
        dp[3][2] = 1;
        dp[3][3] = 1;

        for(int i=4; i<=n; i++){
            dp[i][1] = dp[i-1][2] + dp[i-1][3];
            dp[i][2] = dp[i-2][1] + dp[i-2][3];
            dp[i][3] = dp[i-3][1] + dp[i-3][2];

            dp[i][1] %= MOD;
            dp[i][2] %= MOD;
            dp[i][3] %= MOD;
        }

        long long Answer = (dp[n][1] + dp[n][2] + dp[n][3]) % MOD;
        cout << Answer << '\n';
    }


    return 0;
}

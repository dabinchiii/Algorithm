#include <bits/stdc++.h>

using namespace std;

typedef struct stuff{
    int w, v;
}stuff;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<stuff> stuffArr(n + 1);
    for(int i=1; i<=n; i++){
        cin >> stuffArr[i].w >> stuffArr[i].v;
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = dp[i-1][j];

            if(j - stuffArr[i].w < 0) continue;
            dp[i][j] = max(dp[i][j], dp[i-1][j - stuffArr[i].w] + stuffArr[i].v);
        }
    }

    cout << dp[n][k];

    return 0;
}

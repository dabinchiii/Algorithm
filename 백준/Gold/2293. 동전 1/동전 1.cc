#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_K 10000

using namespace std;

int n, k;
int coin[MAX_N];
vector<int> dp(MAX_K + 1, 0);

void solve(){
    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j] += dp[j - coin[i]];
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }

    solve();

    cout << dp[k];

    return 0;
}

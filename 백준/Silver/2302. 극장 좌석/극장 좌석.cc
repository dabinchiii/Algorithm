#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<bool> vip(n + 1, false);
    vip[0] = true;

    int vipNum;
    for(int i=0; i<m; i++){
        cin >> vipNum;
        vip[vipNum] = true;
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = dp[i - 1];
        if(!vip[i-1] && !vip[i]){
            dp[i] += dp[i - 2];
        }
    }

    cout << dp[n];

    return 0;
}

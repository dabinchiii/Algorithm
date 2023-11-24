#include <bits/stdc++.h>
#define MAX 10000001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> card(n + 1);
    for(int i=1; i<=n; i++){
        cin >> card[i];
    }

    vector<int> dp(n + 1, MAX);
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = min(dp[i], dp[i-j] + card[j]);
        }
    }

    cout << dp[n];

    return 0;
}

#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }

    vector<int> dp(k+1, MAX);
    dp[0] = 0;

    for(int i=1; i<=k; i++){
        for(int x : coin){
            if(i - x < 0 || dp[i - x] == MAX) continue;

            dp[i] = min(dp[i], dp[i-x] + 1);
        }
    }

    cout << (dp[k] != MAX ? dp[k] : -1);

    return 0;
}

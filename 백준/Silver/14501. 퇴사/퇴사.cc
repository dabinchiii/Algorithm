#include <bits/stdc++.h>

using namespace std;

int n;
int t[16], p[16];
int dp[16];
int answer;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> t[i] >> p[i];
    }

    for(int i=n-1; i>=0; i--){
        int end_day = i + t[i] - 1;

        dp[i] = dp[i+1];
        if(end_day < n){
            dp[i] = max(dp[i], p[i] + dp[end_day+1]);
        }
    }

    answer = dp[0];
    cout << answer;

    return 0;
}

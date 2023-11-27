#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<double> dp(n);
    cin >> dp[0];

    double Answer = 0;
    for(int i=1; i<n; i++){
        cin >> dp[i];
        dp[i] = max(dp[i], dp[i-1] * dp[i]);
        Answer = max(Answer, dp[i]);
    }

    cout << fixed;
    cout.precision(3);
    cout << Answer;

    return 0;
}

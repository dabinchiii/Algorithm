#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x, y;
    cin >> x >> y;

    int n = x.length();
    int m = y.length();

    x = ' ' + x;
    y = ' ' + y;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<pair<int, int>>> from(n + 1, vector<pair<int, int>>(m + 1));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i] == y[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                from[i][j] = {i-1, j-1};
            }
            else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                from[i][j] = {i-1, j};
            }
            else{
                dp[i][j] = dp[i][j-1];
                from[i][j] = {i, j-1};
            }
        }
    }

    cout << dp[n][m];
    if(dp[n][m] > 0){
        string lcs;

        pair<int, int> curr = {n, m};
        while(dp[curr.first][curr.second] > 0){
            if(x[curr.first] == y[curr.second]){
                lcs.push_back(x[curr.first]);
            }
            curr = from[curr.first][curr.second];
        }

        reverse(lcs.begin(), lcs.end());
        cout << '\n' << lcs;
    }

    return 0;
}

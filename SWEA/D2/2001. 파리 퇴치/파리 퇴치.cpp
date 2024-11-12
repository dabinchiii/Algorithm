#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[16][16], pSum[16][16];
int ans;

void solve(){
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
            pSum[i][j] = board[i][j] + pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];
        }
    }

    ans = -1;

    int currSum;
    for(int i=m; i<=n; i++){
        for(int j=m; j<=n; j++){
            currSum = pSum[i][j] - pSum[i - m][j] - pSum[i][j - m] + pSum[i - m][j - m];
            ans = max(ans, currSum);
        }
    }


    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int test_case=1; test_case<=T; test_case++){
        solve();
        cout << '#' << test_case << ' ' << ans << '\n';
    }

    return 0;
}

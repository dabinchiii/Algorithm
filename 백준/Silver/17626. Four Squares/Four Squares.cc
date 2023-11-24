#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> squares;
    int num = 1;
    while(1){
        int square = num * num;
        if(square > n) break;
        squares.push_back(square);
        num++;
    }

    vector<int> dp(n + 1, 0);
    for(int i=1; i<=n; i++){
        dp[i] = i;
        for(int x : squares){
            if(i - x < 0) break;
            dp[i] = min(dp[i], dp[i-x] + 1);
        }
    }

    cout << dp[n];

    return 0;
}

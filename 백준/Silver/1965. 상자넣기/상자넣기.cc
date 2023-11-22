#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> dp(n);
    int Answer = -1;
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        Answer = max(Answer, dp[i]);
    }

    cout << Answer;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int nums[n];
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int dp[n];
    for(int i=0; i<n; i++){
        dp[i] = nums[i];
        for(int j=i-1; j>=0; j--){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
    }

    int Answer = -1;
    for(int x : dp){
        Answer = max(Answer, x);
    }

    cout << Answer;

    return 0;
}

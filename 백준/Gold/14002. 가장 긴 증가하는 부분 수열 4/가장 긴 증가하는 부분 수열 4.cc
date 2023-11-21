#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // dp로 LIS인데 경로까지 구해라
    vector<int> arr(n), dp(n), path(n, -1);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int AnswerCnt = -1, currLast;

    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j] >= arr[i]) continue;
            if(dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                path[i] = j;
            }
        }

        if(AnswerCnt < dp[i]){
            AnswerCnt = dp[i];
            currLast = i;
        }

    }

    cout << AnswerCnt << '\n';

    vector<int> AnswerPath;
    while(currLast != -1){
        AnswerPath.push_back(arr[currLast]);
        currLast = path[currLast];
    }

    for(auto it=AnswerPath.rbegin(); it!=AnswerPath.rend(); it++){
        cout << *it << ' ';
    }

    return 0;
}

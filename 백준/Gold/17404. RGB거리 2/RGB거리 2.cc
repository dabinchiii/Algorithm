#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_COST 1000001

using namespace std;

int n;
vector<vector<int>> arr(MAX_N, vector<int>(3)); // 0: R, 1: G, 2: B

int getCost(int first, int last){
    vector<vector<int>> dp(arr);

    dp[0][0] = dp[0][1] = dp[0][2] = MAX_COST;
    dp[0][first] = arr[0][first];

    for(int i=1; i<n-1; i++){
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }

    int cost = arr[n-1][last];
    if(last == 0) cost += min(dp[n-2][1], dp[n-2][2]);
    else if(last == 1) cost += min(dp[n-2][0], dp[n-2][2]);
    else cost += min(dp[n-2][0], dp[n-2][1]);

    return cost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    int Answer = MAX_COST;
    for(int i=0; i<3; i++){ // 1번 집 색
        for(int j=0; j<3; j++){ // N번 집 색
            if(i == j) continue;
            int cost = getCost(i, j);
            Answer = min(Answer, cost);
        }
    }

    cout << Answer;

    return 0;
}

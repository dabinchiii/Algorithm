#include <bits/stdc++.h>

using namespace std;

typedef struct stuff{
    int w, v;
}stuff;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<stuff> stuffArr(n);
    for(int i=0; i<n; i++){
        cin >> stuffArr[i].w >> stuffArr[i].v;
    }

    vector<int> dp(k+1, 0);

    for(stuff curr : stuffArr){
        for(int i=k; i>=1; i--){
            if(i - curr.w < 0) continue;
            dp[i] = max(dp[i], dp[i - curr.w] + curr.v);
        }
    }

    cout << dp[k];

    return 0;
}

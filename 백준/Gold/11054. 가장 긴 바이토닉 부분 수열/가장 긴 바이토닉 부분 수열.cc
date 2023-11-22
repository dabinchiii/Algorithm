#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n), dp1(n), dp2(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        dp1[i] = 1;

        for(int j=0; j<i; j++){
            if(arr[j] >= arr[i]) continue;
            dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }

    for(int i=n-1; i>=0; i--){
        dp2[i] = 1;

        for(int j=n-1; j>i; j--){
            if(arr[j] >= arr[i]) continue;
            dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }

    int Answer = -1;
    for(int i=0; i<n; i++){
        Answer = max(Answer, dp1[i] + dp2[i] - 1);
    }

    cout << Answer;

    return 0;
}

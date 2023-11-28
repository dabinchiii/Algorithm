#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<int> dp1(n + 1, 1), dp2(n + 1, 1);
    int Answer = 1;

    cin >> arr[1];
    for(int i=2; i<=n; i++){
        cin >> arr[i];

        if(arr[i] >= arr[i-1]) dp1[i] = dp1[i-1] + 1;
        if(arr[i] <= arr[i-1]) dp2[i] = dp2[i-1] + 1;

        Answer = max(Answer, max(dp1[i], dp2[i]));
    }

    cout << Answer;

    return 0;
}

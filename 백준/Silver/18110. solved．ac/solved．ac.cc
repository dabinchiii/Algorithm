#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    if(n == 0){
        cout << 0;
        return;
    }

    sort(arr.begin(), arr.end());

    int exc = round(n * 0.15);
    int sum = 0;
    for(int i = exc; i<n - exc; i++) sum += arr[i];

    int ans = round((double)sum / (n - 2 * exc));
    cout << ans;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n * n);
    for(int i=0; i<n*n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());

    cout << arr[n-1];

    return 0;
}

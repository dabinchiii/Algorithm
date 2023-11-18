#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int Answer = 0;

    int right = -1;

    for(int curr : arr){
        if(curr > right){
            right = curr + (l - 1);
            Answer++;
        }
    }

    cout << Answer;

    return 0;
}

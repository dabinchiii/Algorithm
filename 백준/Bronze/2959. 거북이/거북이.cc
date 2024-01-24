#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr(4);
    for(int i=0; i<4; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int w = min(arr[0], arr[1]);
    int h = min(arr[2], arr[3]);

    cout << w * h;

    return 0;
}

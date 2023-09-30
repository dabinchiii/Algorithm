#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    long long Answer = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != i+1){
            Answer += abs(arr[i] - (i+1));
        }
    }

    cout << Answer;

    return 0;
}

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

    int currMax = arr[n-1];
    int Answer = 1;

    for(int i=n-2; i>=0; i--){
        if(arr[i] > currMax){
            Answer++;
            currMax = arr[i];
        }
    }

    cout << Answer;

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[50];

void solve(){
    cin >> n;

    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr + n);

    for(int i=0; i<n; i++) cout << arr[i] << ' ';
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;  
    cin >> T;

    for(int t=1; t<=T; t++){
        cout << '#' << t << ' ';
        solve();
        cout << '\n';
    }

    return 0;
}
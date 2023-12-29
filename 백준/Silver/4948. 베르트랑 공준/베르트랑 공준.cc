#include <bits/stdc++.h>
#define MAX_N 123456
#define MAX_2N (2*MAX_N)

using namespace std;

vector<int> arr(MAX_2N + 1, 1);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=2; i<=MAX_N; i++){
        for(int j=2 * i; j<=MAX_2N; j+=i){
            arr[j] = 0;
        }
    }

    for(int i=1; i<= MAX_2N; i++){
        arr[i] += arr[i - 1];
    }

    int n;
    while(1){
        cin >> n;
        if(n == 0) break;

        cout << arr[2 * n] - arr[n] << '\n';
    }

    return 0;
}

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

    vector<vector<long long>> visited(n-1, vector<long long>(21, 0));
    visited[0][arr[0]] = true;
    for(int i=1; i<n-1; i++){
        for(int j=0; j<=20; j++){
            if(visited[i-1][j] == 0) continue;

            int left = j - arr[i];
            if(left >= 0){
                visited[i][left] += visited[i-1][j];
            }

            int right = j + arr[i];
            if(right <= 20){
                visited[i][right] += visited[i-1][j];
            }
        }
    }

    cout << visited[n-2][arr[n-1]];

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
            arr[i][j] += max(arr[i-1][j-1], max(arr[i-1][j], arr[i][j-1]));
        }
    }

    cout << arr[n][m];

    return 0;
}

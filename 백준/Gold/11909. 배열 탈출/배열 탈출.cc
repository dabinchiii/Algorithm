#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> cost(n + 1, vector<int>(n + 1, -1));
    cost[1][1] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j - 1 > 0){
                int fromLeft = cost[i][j - 1];
                if(arr[i][j] >= arr[i][j - 1]){
                    fromLeft += arr[i][j] - arr[i][j - 1] + 1;
                }
                cost[i][j] = fromLeft;
            }

            if(i - 1 > 0){
                int fromTop = cost[i - 1][j];
                if(arr[i][j] >= arr[i - 1][j]){
                    fromTop += arr[i][j] - arr[i - 1][j] + 1;
                }

                if(cost[i][j] == -1) cost[i][j] = fromTop;
                else cost[i][j] = min(cost[i][j], fromTop);
            }
        }
    }

    cout << cost[n][n];

    return 0;
}

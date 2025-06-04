#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[2001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, true));
    
    for(int i=1; i<n; i++){
        if(arr[i] != arr[i + 1]) dp[i][i + 1] = false;
    }
    
    for(int i=2; i<=n - 1; i++){
        for(int j=1; j<=n; j++){
            int x = j, y = j + i;
            
            if(y > n) break;
            
            if(arr[x] != arr[y] || !dp[x + 1][y - 1]){
                dp[x][y] = false;
            }
        }
    }
    
    int m;
    cin >> m;
    
    int s, e;
    for(int i=0; i<m; i++){
        cin >> s >> e;
        cout << (dp[s][e] ? 1 : 0) << '\n';
    }
    
    return 0;
}

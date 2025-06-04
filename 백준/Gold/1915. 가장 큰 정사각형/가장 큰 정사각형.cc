#include <iostream>
#include <vector>

using namespace std;

int n, m;
int sum[1001][1001];
int ans;

void solve(){
    for(int len = min(n, m); len>=1; len--){
        
        for(int i=0; i<n; i++){
            int x = i + len;
            if(x > n) break;
            
            for(int j=0; j<m; j++){
                int y = j + len;
                if(y > m) break;
                
                int area = sum[x][y] - sum[x][j] - sum[i][y] + sum[i][j];
                if(area == len * len){
                    ans = area;
                    return;
                }
            }
        }
    }
    
    return;
}
int main(){
    cin >> n >> m;
    
    string str;
    for(int i=1; i<=n; i++){
        cin >> str;
        for(int j=1; j<=m; j++){
            sum[i][j] = str[j - 1] - '0';
            sum[i][j] += sum[i][j-1] + sum[i-1][j];
            sum[i][j] -= sum[i-1][j-1];
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

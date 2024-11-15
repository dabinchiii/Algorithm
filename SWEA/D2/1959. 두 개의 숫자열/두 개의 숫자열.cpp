#include <iostream>

using namespace std;

int n, m;
int a[20], b[20];
int ans;

void solve(){
    cin >> n >> m;
    
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    ans = -99999999;
    int sum;
    if(n > m){
        for(int i=0; i<n - m + 1; i++){
            sum = 0;

            for(int j=0; j<m; j++){
                sum += a[i + j] * b[j];
            }

            ans = max(ans, sum);
        }
    }
    else{
        for(int i=0; i<m - n + 1; i++){
            sum = 0;

            for(int j=0; j<n; j++){
                sum += a[j] * b[i + j];
            }

            ans = max(ans, sum);
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;  
    cin >> T;

    for(int t=1; t<=T; t++){
        solve();
        cout << '#' << t << ' ' << ans << '\n';
    }

    return 0;
}
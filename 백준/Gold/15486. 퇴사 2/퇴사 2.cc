#include <iostream>
#include <vector>

#define MAX_N 1500000

using namespace std;

int n;
vector<pair<int, int>> v[MAX_N + 1];
int dp[MAX_N + 1];
int ans;

void solve(){
    for(int i=1; i<=n; i++){
        dp[i] = dp[i - 1];
        for(pair<int, int> curr : v[i]){
            dp[i] = max(dp[i], dp[curr.first - 1] + curr.second);
        }
    }
    
    ans = dp[n];
    
    return;
}

int main(){
    cin >> n;
    
    int t, p;
    for(int i=1; i<=n; i++){
        cin >> t >> p;
        int endDate = i + t - 1;
        
        if(endDate > n) continue;
        
        v[endDate].push_back({i, p});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

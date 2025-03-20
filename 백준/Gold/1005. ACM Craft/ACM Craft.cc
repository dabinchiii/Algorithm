#include <iostream>
#include <vector>

using namespace std;

int n, k, w;
int d[1001];
vector<int> g[1001]; // 역방향

int dp[1001];

void getInput(){
    cin >> n >> k;
    
    for(int i=1; i<=n; i++){
        g[i].clear();
        dp[i] = -1;
    }
    
    for(int i=1; i<=n; i++){
        cin >> d[i];
    }
    
    int x, y;
    for(int i=0; i<k; i++){
        cin >> x >> y;
        g[y].push_back(x);
    }
    
    cin >> w;
    
    return;
}

int build(int idx){
    if(dp[idx] == -1){
        int t = 0;
        for(int curr : g[idx]){
            t = max(t, build(curr));
        }
        
        dp[idx] = t + d[idx];
    }
    
    return dp[idx];
}

void solve(){
    cout << build(w) << endl;
    
    return;
}

int main(){
    int T;
    cin >> T;
    
    for(int test_cast=1; test_cast<=T; test_cast++){
        getInput();
        solve();
    }
    
    return 0;
}

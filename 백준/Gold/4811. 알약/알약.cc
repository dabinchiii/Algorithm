#include <iostream>

#define MAX_N 30

using namespace std;

int N;
long long dp[MAX_N + 1][MAX_N + 1];

long long dfs(int whole, int half){
    if(dp[whole][half] != -1) return dp[whole][half];
    
    if(whole == 0) return dp[whole][half] = dfs(whole, half - 1);
    if(half == 0) return dp[whole][half] = dfs(whole - 1, half + 1);
    
    return dp[whole][half] = dfs(whole - 1, half + 1) + dfs(whole, half - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0; i<=MAX_N; i++){
        for(int j=0; j<=MAX_N; j++){
            dp[i][j] = -1;
        }
    }
    
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = 1;
    
    while(true){
        cin >> N;
        if(N == 0) break;
        cout << dfs(N, 0) << '\n';
    }
    
    
    return 0;
}

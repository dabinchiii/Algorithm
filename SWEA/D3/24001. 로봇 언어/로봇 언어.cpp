#include <iostream>

using namespace std;

string comm;
int len;
int ans;

int solve(){
    ans = 1;
    
    cin >> comm;
    len = (int)comm.length();
    
    int dp[50][2];
    
    if(comm[0] == 'R') dp[0][0] = dp[0][1] = 1;
    else if(comm[0] == 'L') dp[0][0] = dp[0][1] = -1;
    else{
        dp[0][0] = -1;
        dp[0][1] = 1;
    }
    
    for(int i=1; i<len; i++){
        if(comm[i] == 'R'){
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        }
        else if(comm[i] == 'L'){
            dp[i][0] = dp[i - 1][0] - 1;
            dp[i][1] = dp[i - 1][1] - 1;
        }
        else{
            dp[i][0] = dp[i - 1][0] - 1;
            dp[i][1] = dp[i - 1][1] + 1;
        }
        
        ans = max(ans, max(abs(dp[i][0]), abs(dp[i][1])));
    }
    
    return ans;
}

int main(){
    int T;
    cin >> T;
    
    for(int t=1; t<=T; t++){
        cout << solve() << '\n';
    }
    
    return 0;
}

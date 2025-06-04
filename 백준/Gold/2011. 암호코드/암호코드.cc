#include <iostream>
#include <vector>

using namespace std;

string text;
int len;
int ans;

void solve(){
    vector<int> arr(len + 1);
    
    for(int i=0; i<len; i++){
        arr[i] = text[i] - '0';
    }
    arr[len] = -1;
    
    vector<int> dp(len + 1, 0);
    dp[len] = 1;
    dp[len - 1] = (arr[len - 1] != 0 ? 1 : 0);
    
    for(int i=len - 2; i>=0; i--){
        int curr = arr[i];
        
        dp[i] = dp[i + 1];
        
        if(curr == 0){
            dp[i] = 0;
        }
        else if(curr == 1){
            dp[i] += dp[i + 2];
        }
        else if(curr == 2 && (arr[i + 1] >= 0 && arr[i + 1] <= 6)){
            dp[i] += dp[i + 2];
        }
        
        dp[i] %= 1000000;
    }
    
    ans = dp[0];
    
    return;
}

int main(){
    cin >> text;
    len = (int)text.length();
    
    solve();
    
    cout << ans;
    
    return 0;
}

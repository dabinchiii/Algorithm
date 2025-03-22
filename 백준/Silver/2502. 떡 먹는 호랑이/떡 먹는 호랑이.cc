#include <iostream>

using namespace std;

int d, k;
int ansA, ansB;

void solve(){
    int dp[k];
    
    for(int a = 1; a<=k; a++){
        for(int b = 1; b<=k; b++){
            dp[1] = a;
            dp[2] = b;
            
            bool ok = true;
            for(int i=3; i<=d; i++){
                dp[i] = dp[i - 1] + dp[i - 2];
                
                if(dp[i] > k){
                    ok = false;
                    break;
                }
            }
            
            if(ok && dp[d] == k){
                ansA = a;
                ansB = b;
                return;
            }
        }
    }
    
    return;
}

int main(){
    cin >> d >> k;
    
    solve();
    
    cout << ansA << endl << ansB;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K;
int w[1 << 21];
long long ans;

void solve(){
    ans = 0;
    int currDepth = K;
    while(currDepth > 0){
        int start = (1 << currDepth);
        
        for(int i=0; i<start; i+=2){
            int left = start + i;
            int right = left + 1;
            int maxV = max(w[left], w[right]);
            
            w[left >> 1] += maxV;
            w[1] += maxV;
        }
        
        --currDepth;
    }
    
    ans = w[1];
    
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> K;
    
    int last = (1 << (K + 1)) - 1;
    for(int i=2; i<=last; i++){
        cin >> w[i];
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

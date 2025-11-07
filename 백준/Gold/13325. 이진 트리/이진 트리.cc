#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K;
int w[1 << 22], cw[1 << 22];
int last;
long long ans;

void solve(){
    ans = 0;
    int currDepth = K;
    while(currDepth > 0){
        int start = (1 << currDepth);
        
        for(int i=0; i<start; i+=2){
            int left = start + i;
            int right = left + 1;
            int maxV = max(w[left] + cw[left], w[right] + cw[right]);
            cw[left >> 1] = maxV;
            
            w[left] = maxV - cw[left];
            w[right] = maxV - cw[right];
        }
        
        --currDepth;
    }
    
    for(int i=2; i<=last; i++){
        ans += w[i];
    }
    
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> K;
    
    last = (1 << (K + 1)) - 1;
    for(int i=2; i<=last; i++){
        cin >> w[i];
        w[1] += w[i];
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

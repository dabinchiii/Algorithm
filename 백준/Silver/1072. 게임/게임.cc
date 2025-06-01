#include <iostream>

using namespace std;

long x, y;
long ans;

void solve(){
    long z = (y * 100) / x;
    
    ans = -1;
    
    long left = 1, right = x;
    while(left <= right){
        long mid = (left + right) / 2;
        long newZ = ((y + mid) * 100) / (x + mid);
        
        if(newZ > z){ // z가 변하긴했지만 현재 mid가 최선인지는 모름
            ans = mid;
            right = mid - 1;
        }
        else{ // 아직 부족함
            left = mid + 1;
        }
        
    }
    
    return;
}

int main(){
    cin >> x >> y;
    
    solve();
    
    cout << ans;
    
    return 0;
}

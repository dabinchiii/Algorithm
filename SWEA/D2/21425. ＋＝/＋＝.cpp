#include <iostream>

using namespace std;

void solve(){
    int ans = 0;
    int x, y, n;
    
    cin >> x >> y >> n;
    
    while(x <= n && y <= n){
        if(x > y) y += x;
        else x += y;
        ans++;
    }
    
    cout << ans << '\n';
    
    return;
}
int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++) solve();
    
    return 0;
}

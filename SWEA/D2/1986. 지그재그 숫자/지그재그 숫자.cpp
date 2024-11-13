#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;

void solve(){
    cin >> n;

    ans = 0;

    for(int i=1; i<=n; i++){
        if(i % 2) ans += i;
        else ans -= i;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=1; t<=T; t++){
        solve();
        cout << "#" << t << ' ' << ans << '\n';
    }

    return 0;
}
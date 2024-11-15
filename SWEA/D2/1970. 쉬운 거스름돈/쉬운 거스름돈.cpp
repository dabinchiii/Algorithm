#include <iostream>
#include <algorithm>

using namespace std;

int n;
int ans[8];

int unit[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};

void solve(){
    cin >> n;

    for(int i=0; i<8; i++) ans[i] = 0;

    int curr = n;
    for(int i=0; i<8; i++){
        if(curr < unit[i]) continue;

        ans[i] += curr / unit[i];
        curr %= unit[i];
    }

    for(int i=0; i<8; i++) cout << ans[i] << ' ';

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;  
    cin >> T;

    for(int t=1; t<=T; t++){
        cout << '#' << t << '\n';
        solve();
        cout << '\n';
    }

    return 0;
}
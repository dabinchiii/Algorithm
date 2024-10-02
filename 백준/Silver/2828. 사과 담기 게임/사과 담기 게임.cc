#include <bits/stdc++.h>

using namespace std;

int n, m, j;
int apple[20];
int ans;

void solve(){
    int left = 1, right = m;

    for(int i=0; i<j; i++){
        int curr = apple[i];

        if(curr < left){
            ans += left - curr;
            left = curr;
            right = curr + m - 1;
        }
        else if(curr > right){
            ans += curr - right;
            right = curr;
            left = curr - m + 1;
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> j;

    for(int i=0; i<j; i++){
        cin >> apple[i];
    }

    solve();

    cout << ans;

    return 0;
}

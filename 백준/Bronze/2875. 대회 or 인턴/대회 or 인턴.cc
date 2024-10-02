#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int ans = min(n / 2, m);

    while((n + m) - 3 * ans < k) ans--;

    cout << ans;

    return 0;
}

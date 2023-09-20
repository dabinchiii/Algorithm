#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n, m;
    cin >> k >> n >> m;
    cout << max((k * n) - m, 0);

    return 0;
}

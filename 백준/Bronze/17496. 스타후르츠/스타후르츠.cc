#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, c, p;
    cin >> n >> t >> c >> p;

    cout << ((n - 1) / t) * c * p;

    return 0;
}

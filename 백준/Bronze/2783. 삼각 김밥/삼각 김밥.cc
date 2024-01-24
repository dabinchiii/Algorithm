#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, n;
    cin >> x >> y >> n;

    double minUnitPrice = (double)x / (double)y;
    int a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        minUnitPrice = min(minUnitPrice, (double)a / (double)b);
    }

    cout << fixed;
    cout.precision(2);
    cout << minUnitPrice * 1000;

    return 0;
}

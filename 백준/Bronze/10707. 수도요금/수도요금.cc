#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int p;
    cin >> p;

    int x = a * p;
    int y = b + max(0, p - c) * d;

    cout << min(x, y);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, a, b, c, d;
    cin >> l;
    cin >> a >> b >> c >> d;

    int korean = a / c + (a % c != 0 ? 1 : 0);
    int math = b / d + (b % d != 0 ? 1 : 0);

    cout << l - max(korean, math);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b >= 2 * c ? a + b - 2 * c : a + b);

    return 0;
}

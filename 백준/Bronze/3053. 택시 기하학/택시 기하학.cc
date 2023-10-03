#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const double pi = 3.14159265359;

    int r;
    cin >> r;

    cout << fixed;
    cout.precision(6);
    cout << pi * r * r << '\n';
    cout << pow(sqrt(2 * r * r), 2);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);

    cout << (b * (b + 1)) / 2 - ((a - 1) * a) / 2;

    return 0;
}

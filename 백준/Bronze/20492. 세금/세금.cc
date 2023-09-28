#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a = n * 0.78;
    int b = n - n * 0.2 * 0.22;

    cout << a << ' ' << b;

    return 0;
}

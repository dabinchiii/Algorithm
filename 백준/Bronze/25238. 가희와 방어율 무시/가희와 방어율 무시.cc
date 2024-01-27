#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    cout << ((a * (100 - b) * 0.01) < 100 ? 1 : 0);

    return 0;
}

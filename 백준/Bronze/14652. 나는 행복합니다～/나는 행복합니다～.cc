#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int row = k / m;
    int col = k % m;

    cout << row << ' ' << col;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int n, c;
        cin >> n >> c;
        cout << n / c + (n % c == 0 ? 0 : 1) << '\n';
    }

    return 0;
}

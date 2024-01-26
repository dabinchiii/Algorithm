#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n, m;
        cin >> n >> m;

        int u = (2 * m) - n;
        cout << u << ' ' << m - u << '\n';
    }

    return 0;
}

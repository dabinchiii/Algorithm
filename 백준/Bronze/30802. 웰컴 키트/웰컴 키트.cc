#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int num[6];
    int t, p;

    cin >> n;

    for(int i=0; i<6; i++) cin >> num[i];

    cin >> t >> p;

    int cntT = 0;

    for(int i=0; i<6; i++){
        cntT += num[i] / t + (num[i] % t ? 1 : 0);
    }

    cout << cntT << '\n';
    cout << n / p << ' ' << n % p;

    return 0;
}

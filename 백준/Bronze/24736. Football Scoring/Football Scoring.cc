#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, f, s, p, c;
    for(int i=0; i<2; i++){
        cin >> t >> f >> s >> p >> c;
        int Answer = 6 * t + 3 * f + 2 * s + p + 2 * c;
        cout << Answer << ' ';
    }

    return 0;
}

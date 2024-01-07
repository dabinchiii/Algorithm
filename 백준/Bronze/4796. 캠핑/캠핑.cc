#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, p, v;
    int test_case = 1;
    while(1){
        cin >> l >> p >> v;
        if(l + p + v == 0) break;

        int Answer = (v / p) * l + min(l, v % p);
        cout << "Case " << test_case << ": " << Answer << '\n';
        test_case++;
    }

    return 0;
}

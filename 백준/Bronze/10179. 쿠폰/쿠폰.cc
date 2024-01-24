#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    cout << fixed;
    cout.precision(2);

    for(int t=0; t<T; t++){
        double price;
        cin >> price;
        cout << '$' << price * 0.8 << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << stoll(a+b) + stoll(c+d);

    return 0;
}

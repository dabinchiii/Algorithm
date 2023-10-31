#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l;
    cin >> l;

    cout << l / 5 + (l % 5 ? 1 : 0);

    return 0;
}

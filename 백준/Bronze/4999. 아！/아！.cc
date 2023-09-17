#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string jh, dt;
    cin >> jh >> dt;

    cout << ( (int)jh.length() >= (int)dt.length() ? "go" : "no");

    return 0;
}

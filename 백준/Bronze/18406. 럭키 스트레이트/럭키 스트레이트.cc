#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int left = 0, right = 0;
    for(int i=0; i<(int)str.length() / 2; i++){
        left += str[i] - '0';
        right += str[str.length()-i-1] - '0';
    }

    cout << (left == right ? "LUCKY" : "READY");

    return 0;
}

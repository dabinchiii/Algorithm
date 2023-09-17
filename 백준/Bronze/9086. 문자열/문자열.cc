#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        string str;
        cin >> str;

        cout << str[0] << str[str.length()-1] << '\n';
    }

    return 0;
}

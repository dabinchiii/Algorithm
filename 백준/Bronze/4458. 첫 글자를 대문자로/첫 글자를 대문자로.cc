#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string flush;
    getline(cin, flush);

    string str;
    for(int i=0; i<n; i++){
        getline(cin, str);

        if(str[0] >= 'a' && str[i] <= 'z'){
            str[0] -= 'a' - 'A';
        }

        cout << str << '\n';
    }

    return 0;
}

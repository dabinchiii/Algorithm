#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin, str);

    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = 'a' + ((str[i] - 'a' + 13) % 26);
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = 'A' + ((str[i] - 'A' + 13) % 26);
        }
    }

    cout << str;

    return 0;
}

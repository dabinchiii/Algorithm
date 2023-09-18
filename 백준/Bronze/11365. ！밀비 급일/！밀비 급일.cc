#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    while(true){
        getline(cin, str);
        if(str == "END") break;

        for(int i=str.length()-1; i>=0; i--){
            cout << str[i];
        }
        cout << '\n';
    }

    return 0;
}

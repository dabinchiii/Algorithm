#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    map<char, int> m;
    string charList = "-\\(@?>&%";
    for(int i=0; i<8; i++){
        m[charList[i]] = i;
    }
    m['/'] = -1;

    string str;
    while(1){
        cin >> str;
        if(str == "#") break;

        int Answer = 0, unit = 1;
        for(int i=str.length() - 1; i>=0; i--){
            Answer += m[str[i]] * unit;
            unit *= 8;
        }

        cout << Answer << '\n';
    }

    return 0;
}

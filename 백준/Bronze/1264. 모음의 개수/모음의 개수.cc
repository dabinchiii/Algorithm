#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string vowel = "aeiouAEIOU";

    string str;
    while(true){
        getline(cin, str);
        if(str == "#") break;

        int Answer = 0;
        for(int i=0; i<str.length(); i++){
            for(int j=0; j<vowel.length(); j++){
                if(str[i] == vowel[j]) Answer++;
            }
        }

        cout << Answer << '\n';
    }

    return 0;
}

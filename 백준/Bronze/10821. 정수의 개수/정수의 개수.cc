#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int Answer = 0;

    for(int i=0; i<str.length(); i++){
        if(str[i] == ',') Answer++;
    }
    Answer += 1;

    cout << Answer;

    return 0;
}

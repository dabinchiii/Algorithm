#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    str = " " + str;

    int Answer = 0;

    for(int i=1; i<str.length(); i++){
        if(str[i] == str[i-1]){
            Answer += 5;
        }
        else{
            Answer += 10;
        }
    }

    cout << Answer;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    str += ",";
    int Answer = 0;

    int start = 0;
    for(int i=0; i<str.length(); i++){
        if(str[i+1] == ','){
            i++;
            Answer += stoi(str.substr(start, i));
            start = i + 1;
        }
    }

    cout << Answer;

    return 0;
}

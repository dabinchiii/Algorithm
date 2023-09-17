#include <bits/stdc++.h>
using namespace std;

string binary(int num){
    string result = "";
    result += (num / 4 == 1) ? '1' : '0';
    num %= 4;

    result += (num / 2 == 1) ? '1' : '0';
    num %= 2;

    result += (num == 1) ? '1' : '0';

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    string first = binary(str[0] - '0');

    if(first[0] == '0') first = first.substr(1);
    if(first[0] == '0') first = first.substr(1);

    cout << first;
    for(int i=1; i<str.length(); i++){
        cout << binary(str[i] - '0');
    }

    return 0;
}

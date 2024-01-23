#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int a, b;
    if(str.length() == 2){
        a = str[0] - '0';
        b = str[1] - '0';
    }
    else if(str.length() == 3){
        if(str[1] == '0'){
            a = 10;
            b = str[2] - '0';
        }
        else{
            a = str[0] - '0';
            b = 10;
        }
    }
    else{
        a = b = 10;
    }

    cout << a + b;

    return 0;
}

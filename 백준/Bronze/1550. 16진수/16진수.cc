#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int Answer = 0;
    int digit = 1;

    for(int i=0; i<str.length(); i++){
        int num = str[str.length() - i - 1];
        num -= (num>='0' && num<='9'? '0':('A' - 10));
        Answer += digit * num;
        digit *= 16;
    }

    cout << Answer;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int cnt = 1;
    for(int i=1; i<str.length(); i++){
        if(str[i] != str[i-1]) cnt++;
    }

    int Answer = cnt / 2;
    cout << Answer;

    return 0;
}

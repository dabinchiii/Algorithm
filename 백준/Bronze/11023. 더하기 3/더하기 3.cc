#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin, str);
    str.push_back(' ');

    int Answer = 0;
    int left = 0, num;
    for(int i=0; i<str.length(); i++){
        if(str[i] != ' ') continue;
        num = stoi(str.substr(left, i - left));
        left = i + 1;
        Answer += num;
    }

    cout << Answer;

    return 0;
}

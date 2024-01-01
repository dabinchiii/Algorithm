#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin, str);

    int cntHappy = 0, cntSad = 0;

    for(int i=0; i<str.length() - 2; i++){
        if(str[i] != ':') continue;
        if(str[i + 1] != '-') continue;

        if(str[i + 2] == ')') cntHappy++;
        else if(str[i + 2] == '(') cntSad++;
    }

    if(cntHappy + cntSad == 0) cout << "none";
    else if(cntHappy == cntSad) cout << "unsure";
    else if(cntHappy > cntSad) cout << "happy";
    else cout << "sad";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool solve(){
    string str;
    cin >> str;

    int len = str.length();
    for(int i=0; i<len / 2; i++){
        if(str[i] != str[len - 1 - i]) return false;
    }

    for(int i=0; i<len / 2 / 2; i++){
        if(str[i] != str[len / 2 - 1 - i]) return false;
        if(str[len / 2 + 1 + i] != str[len - 1 - i]) return false;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cout << "#" << test_case << ' ';
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}

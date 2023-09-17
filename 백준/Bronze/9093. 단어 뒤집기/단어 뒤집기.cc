#include <bits/stdc++.h>
using namespace std;

void solve(string str){
    str += ' ';
    int start = 0;
    for(int i=0; i<str.length(); i++){
        if(str[i] != ' '){
            continue;
        }

        for(int j=0; j<(i - start)/2; j++){
            swap(str[start + j], str[i - j - 1]);
        }

        start = i + 1;
    }


    cout << str << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    string flush;
    getline(cin, flush);

    for(int t=0; t<T; t++){
        string str;
        getline(cin, str);

        solve(str);
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void solve(){
    string soundStr;
    getline(cin, soundStr);
    soundStr.push_back(' ');

    vector<string> arr;
    int start = 0;
    for(int i=0; i<soundStr.length(); i++){
        if(soundStr[i] != ' ') continue;

        arr.push_back(soundStr.substr(start, i - start));
        start = i + 1;
    }

    string str;
    map<string, bool> m;
    while(1){
        getline(cin, str);
        if(str.compare("what does the fox say?") == 0){
            break;
        }

        for(int i=0; i<str.length(); i++){
            if(str[i] != 'g') continue;
            if(str[i + 1] != 'o') continue;
            if(str[i + 2] != 'e') continue;
            if(str[i + 3] != 's') continue;
            if(str[i + 4] != ' ') continue;

            m[str.substr(i + 5)] = true;
        }
    }

    for(string x : arr){
        if(!m[x]) cout << x << ' ';
    }
    cout << '\n';

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    string flush;
    getline(cin, flush);

    for(int t=0; t<T; t++){
        solve();
    }

    return 0;
}

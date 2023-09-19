#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        string str;
        cin >> str;

        vector<bool> arr(26, false);
        for(int i=0; i<str.length(); i++){
            arr[str[i]-'A'] = true;
        }

        int Answer = 0;
        for(int i=0; i<26; i++){
            if(!arr[i]) Answer += 'A' + i;
        }
        cout << Answer << '\n';
    }

    return 0;
}

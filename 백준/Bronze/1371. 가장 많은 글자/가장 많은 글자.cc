#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    vector<int> cnt(26, 0);

    for(int i=0; i<50; i++){
        getline(cin, str);

        for(int j=0; j<str.length(); j++){
            if(str[j] >= 'a' && str[j] <= 'z'){
                cnt[str[j]-'a']++;
            }
        }

    }

    int maxCnt = -1;
    for(int i=0; i<26; i++){
        maxCnt = max(maxCnt, cnt[i]);
    }

    for(int i=0; i<26; i++){
        if(cnt[i] == maxCnt){
            cout << (char)('a' + i);
        }
    }

    return 0;
}

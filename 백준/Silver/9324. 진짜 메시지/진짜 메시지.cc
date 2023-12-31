#include <bits/stdc++.h>

using namespace std;

bool solve(string str){
    vector<int> cnt(26, 0);

    for(int i=0; i<str.length(); i++){
        int idx = str[i] - 'A';
        cnt[idx]++;

        if(cnt[idx] == 3){
            int nxt = i + 1;
            if(nxt == str.length() || str[nxt] != str[i]){
                return false;
            }

            cnt[idx] = 0;
            i++;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        string str;
        cin >> str;

        bool Answer = solve(str);
        cout << (Answer ? "OK" : "FAKE") << '\n';
    }

    return 0;
}

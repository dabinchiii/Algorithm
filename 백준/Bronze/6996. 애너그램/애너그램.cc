#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        string a, b;
        cin >> a >> b;

        int cnt[26];
        for(int i=0; i<26; i++) cnt[i] = 0;

        for(int i=0; i<a.length(); i++){
            cnt[a[i] - 'a']++;
        }
        for(int i=0; i<b.length(); i++){
            cnt[b[i] - 'a']--;
        }

        bool ans = true;
        for(int i=0; i<26; i++){
            if(cnt[i] == 0) continue;
            ans = false;
            break;
        }

        cout << a << " & " << b << " are " << (!ans ? "NOT " : "") << "anagrams.\n";
    }

    return 0;
}

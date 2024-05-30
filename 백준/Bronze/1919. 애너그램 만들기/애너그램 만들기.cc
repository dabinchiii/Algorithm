#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    vector<int> cnt(26, 0);
    for(int i=0; i<a.length(); i++){
        cnt[a[i] - 'a']++;
    }
    for(int i=0; i<b.length(); i++){
        cnt[b[i] - 'a']--;
    }

    int ans = 0;
    for(int i=0; i<26; i++){
        ans += abs(cnt[i]);
    }

    cout << ans;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<char, int> m;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        m[str[0]]++;
    }

    if(m.size() == 1) cout << 1;
    else cout << 0;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans = 0;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;

        if(stoi(str.substr(2)) <= 90) ans++;
    }

    cout << ans;

    return 0;
}

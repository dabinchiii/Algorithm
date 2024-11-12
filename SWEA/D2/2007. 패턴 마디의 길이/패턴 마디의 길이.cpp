#include <bits/stdc++.h>

using namespace std;

string str;
int ans;

void solve(){
    cin >> str;
    ans = -1;

    int len = str.length();
    for(int i=1; i<=10; i++){
        bool flag = true;
        for(int j=0; j<i; j++){
            if(str[j] != str[j + i]){
                flag = false;
                break;
            }
        }

        if(flag){
            ans = i;
            return;
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=1; t<=T; t++){
        solve();
        cout << '#' << t << ' ' << ans << '\n';
    }

    return 0;
}

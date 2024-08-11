#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    str += " ";

    string ans = "";
    int left = 0;
    for(int i=0; i<str.length(); i++){
        if(str[i] != 'X'){
            int len = i - left;
            if(len % 2) break;

            while(len){
                if(len / 4 > 0){
                    ans += "AAAA";
                    len -= 4;
                }
                else if(len / 2 > 0){
                    ans += "BB";
                    len -= 2;
                }
            }
            ans += str[i];

            left = i + 1;
        }
    }

    if(ans.length() == str.length()) cout << ans;
    else cout << -1;

    return 0;
}

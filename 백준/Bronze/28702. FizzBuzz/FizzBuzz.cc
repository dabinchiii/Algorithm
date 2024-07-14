#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str[3];
    int num;
    for(int i=0; i<3; i++){
        cin >> str[i];
        if(str[i][str[i].length() - 1] != 'z'){
            num = stoi(str[i]) + (3 - i);
        }
    }

    string ans = "";

    if(num % 3 == 0) ans += "Fizz";
    if(num % 5 == 0) ans += "Buzz";
    if(ans.length() == 0) ans = to_string(num);

    cout << ans;

    return 0;
}

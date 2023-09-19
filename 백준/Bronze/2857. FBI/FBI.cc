#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int cnt = 0;
    for(int i=1; i<=5; i++){
        cin >> str;
        for(int j=0; j<(int)str.length() - 2; j++){
            if(str[j] != 'F') continue;
            if(str[j+1] != 'B') continue;
            if(str[j+2] != 'I') continue;

            cout << i << ' ';
            cnt++;
            break;
        }
    }

    if(cnt == 0) cout << "HE GOT AWAY!";

    return 0;
}

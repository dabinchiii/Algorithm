#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(1){
        cin >> n;
        if(n == 0) break;

        string num = to_string(n);
        int Answer = 0;

        Answer += num.length() - 1;
        for(int i=0; i<num.length(); i++){
            if(num[i] == '0') Answer += 4;
            else if(num[i] == '1') Answer += 2;
            else Answer += 3;
        }
        Answer += 2;

        cout << Answer << '\n';
    }

    return 0;
}

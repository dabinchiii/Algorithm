#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    while(true){
        getline(cin, str);
        if(str.length() == 0) break;

        int lower = 0, upper = 0, digit = 0, blank = 0;

        for(int i=0; i<str.length(); i++){
            if(str[i] == ' '){
                blank++;
            }
            else if(str[i] >= '0' && str[i] <= '9'){
                digit++;
            }
            else if(str[i] >= 'a' && str[i] <= 'z'){
                lower++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z'){
                upper++;
            }


        }
        cout << lower << ' ' << upper << ' ' << digit << ' ' << blank << '\n';
    }

    return 0;
}

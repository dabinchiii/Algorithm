#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string bin;
    cin >> bin;

    if((int)bin.length() % 3 != 0){
        if((int)bin.length() % 3 == 1){
            bin = "00" + bin;
        }
        else{
            bin = "0" + bin;
        }
    }

    string Answer = "";
    for(int i=0; i < bin.length(); i+=3){
        int num = 0;
        num += (bin[i] == '1' ? 1 : 0) * 4;
        num += (bin[i+1] == '1' ? 1 : 0) * 2;
        num += (bin[i+2] == '1' ? 1 : 0) * 1;

        Answer += to_string(num);
    }

    cout << Answer;

    return 0;
}

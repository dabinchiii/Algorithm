#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int t=0; t<3; t++){
        string str;
        cin >> str;

        int Answer = 1;
        char currCh = str[0];
        int currLen = 1;

        for(int i=1; i<8; i++){
            if(str[i] == currCh){
                currLen++;
                Answer = max(Answer, currLen);
            }
            else{
                currCh = str[i];
                currLen = 1;
            }
        }

        cout << Answer << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int hexToDec(string hex){
    int dec = 0, unit = 1, currNum;
    for(int i=hex.length() - 1; i>=0; i--){
        if(hex[i] >= '0' && hex[i] <= '9') currNum = hex[i] - '0';
        else currNum = hex[i] - 'a' + 10;

        dec += currNum * unit;
        unit *= 16;
    }

    return dec;
}
int octToDec(string oct){
    int dec = 0, unit = 1;
    for(int i=oct.length() - 1; i>=0; i--){
        dec += (oct[i] - '0') * unit;
        unit *= 8;
    }
    return dec;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string strX;
    cin >> strX;

    int decX;
    if(strX[0] != '0') decX = stoi(strX);
    else if(strX[1] == 'x') decX = hexToDec(strX.substr(2));
    else decX = octToDec(strX.substr(1));

    cout << decX;

    return 0;
}

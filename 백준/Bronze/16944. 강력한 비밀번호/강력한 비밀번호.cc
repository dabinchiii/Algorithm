#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    bool conNum = false, conLower = false, conUpper = false, conSp = false;

    char ch;
    for(int i=0; i<n; i++){
        cin >> ch;

        if(ch >= '0' && ch <= '9'){
            conNum = true;
        }
        else if(ch >= 'a' && ch <= 'z'){
            conLower = true;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            conUpper = true;
        }
        else{
            conSp = true;
        }
    }

    int Answer = 0;

    Answer += (!conNum ? 1 : 0);
    Answer += (!conLower ? 1 : 0);
    Answer += (!conUpper ? 1 : 0);
    Answer += (!conSp ? 1 : 0);

    if(n + Answer < 6){
        Answer += 6 - (n + Answer);
    }

    cout << Answer;

    return 0;
}

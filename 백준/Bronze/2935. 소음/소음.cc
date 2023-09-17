#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    char oper;
    cin >> a >> oper >> b;

    string Answer;
    if(oper == '*'){
        Answer = a;
        for(int i=0; i<(int)b.length()-1; i++){
            Answer += "0";
        }
    }
    else{
        if((int)a.length() < (int)b.length()){
            swap(a, b);
        }

        Answer = a;
        int idx = (int)a.length() - (int)b.length();
        Answer[idx] = (Answer[idx] == '0' ? '1' : '2');
    }

    cout << Answer;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        long long a, b, c;
        char oper, eq;
        cin >> a >> oper >> b >> eq >> c;

        bool Answer;
        if(oper == '+'){
            Answer = (a + b == c);
        }
        else if(oper == '-'){
            Answer = (a - b == c);
        }
        else if(oper == '/'){
            Answer = (a / b == c);
        }
        else if(oper == '*'){
            Answer = (a * b == c);
        }

        cout << (Answer ? "correct" : "wrong answer") << '\n';
    }

    return 0;
}

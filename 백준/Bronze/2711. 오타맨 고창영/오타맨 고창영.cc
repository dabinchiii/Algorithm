#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int x;
        string str;
        cin >> x >> str;

        x--;

        string Answer;
        Answer = str.substr(0, x);
        Answer += str.substr(x+1);

        cout << Answer << '\n';
    }

    return 0;
}

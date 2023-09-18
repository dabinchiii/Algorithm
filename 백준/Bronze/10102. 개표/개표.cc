#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v;
    cin >> v;

    string str;
    cin >> str;

    int a = 0, b = 0;
    for(int i=0; i<v; i++){
        if(str[i] == 'A') a++;
        else b++;
    }

    if(a == b) cout << "Tie";
    else cout << (a > b ? "A" : "B");

    return 0;
}

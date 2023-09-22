#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int Answer = a;
    if(c % 2 == 1){
        Answer ^= b;
    }
    cout << Answer;

    return 0;
}

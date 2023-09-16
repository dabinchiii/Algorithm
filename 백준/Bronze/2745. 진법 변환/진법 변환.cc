#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string z;
    int b;
    cin >> z >> b;

    int Answer = 0;
    int digit = 1;

    for(int i=z.length()-1; i>=0; i--){
        int num = z[i];
        num -= (num>='0' && num<='9' ? '0' : ('A' - 10));
        Answer += num * digit;
        digit *= b;
    }

    cout << Answer;

    return 0;
}

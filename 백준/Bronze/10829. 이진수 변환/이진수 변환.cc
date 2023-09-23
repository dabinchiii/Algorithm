#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    string Answer = "";
    while(n>0){
        Answer = (n % 2 ? '1' : '0') + Answer;
        n /= 2;
    }

    cout << Answer;

    return 0;
}

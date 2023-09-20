#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b;
    cin >> n >> b;

    string Answer = "";
    while(n > 0){
        int curr = n % b;
        n /= b;

        char ch;
        if(curr >= 10){
            ch = 'A' + (curr - 10);
        }
        else{
            ch = '0' + curr;
        }

        Answer = ch + Answer;
    }

    cout << Answer;

    return 0;
}

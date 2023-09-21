#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, f;
    cin >> n >> f;

    n /= 100;
    n *= 100;

    int Answer = -1;
    for(int i=0; i<100; i++){
        if((n + i) % f == 0){
            Answer = i;
            break;
        }
    }

    cout << (Answer < 10 ? "0" : "") << Answer;

    return 0;
}

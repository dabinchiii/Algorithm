#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, k, p;
    cin >> c >> k >> p;

    int Answer = 0;
    for(int i=0; i<=c; i++){
        Answer += k * i + p * i * i;
    }
    cout << Answer;

    return 0;
}

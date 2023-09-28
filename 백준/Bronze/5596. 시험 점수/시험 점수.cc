#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 0, b = 0;
    int score;
    for(int i=0; i<4; i++){
        cin >> score;
        a += score;
    }
    for(int i=0; i<4; i++){
        cin >> score;
        b += score;
    }

    cout << max(a, b);

    return 0;
}

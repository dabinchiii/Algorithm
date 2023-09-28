#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int Answer = -1;

    for(int i=n/5; i>=0; i--){
        if((n - 5*i) % 2 == 0){
            Answer = i + (n - 5*i) / 2;
            break;
        }
    }

    cout << Answer;

    return 0;
}

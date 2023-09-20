#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, sum = 0;
    for(int i=0; i<4; i++){
        cin >> num;
        sum += num;
    }

    cout << sum / 60 << '\n' << sum % 60;

    return 0;
}

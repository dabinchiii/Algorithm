#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sum = 0;
    int num;
    for(int i=0; i<5; i++){
        cin >> num;
        sum += num * num;
    }

    cout << sum % 10;

    return 0;
}

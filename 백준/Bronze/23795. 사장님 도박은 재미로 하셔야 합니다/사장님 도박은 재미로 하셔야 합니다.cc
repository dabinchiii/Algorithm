#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, sum = 0;
    while(1){
        cin >> num;
        if(num == -1) break;
        sum += num;
    }
    cout << sum;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long s;
    cin >> s;

    long long n = 0, sum = 0;
    while(s - sum > n){
        n++;
        sum += n;
    }

    cout << n;

    return 0;
}

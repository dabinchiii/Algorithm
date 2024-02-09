#include <bits/stdc++.h>

using namespace std;

int a, b, c;

long long pow(int x){
    if(x == 0) return 1;
    if(x == 1) return a % c;

    long long p = pow(x/2) % c;
    if(x % 2 == 0) return (p * p) % c;
    return ((p * p % c) * (a % c)) % c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    cout << pow(b);

    return 0;
}

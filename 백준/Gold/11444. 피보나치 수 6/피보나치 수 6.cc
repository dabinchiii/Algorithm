#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

map<long long, long long> m;

long long fib(long long n){
    if(m[n]) return m[n];

    if(n % 2){ // 홀수
        long long f1 = fib((n + 1) / 2);
        long long f2 = fib((n - 1) / 2);
        m[n] = (f1 * f1 % MOD + f2 * f2 % MOD) % MOD;
    }
    else{ // 짝수
        m[n] = (fib(n / 2) * (fib(n / 2 + 1) + fib(n / 2 - 1) % MOD)) % MOD;
    }

    return m[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    m[0] = 0;
    m[1] = 1;
    m[2] = 1;

    long long n;
    cin >> n;
    cout << fib(n);

    return 0;
}

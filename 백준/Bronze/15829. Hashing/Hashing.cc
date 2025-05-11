#include <iostream>
#include <math.h>

using namespace std;

int main(){
    long long r = 31;
    long long M = 1234567891;
    
    int l;
    cin >> l;
    
    string str;
    cin >> str;
    
    long long ans = 0;
    
    long long numR = 1;
    for(int i=0; i<l; i++){
        ans += ((long long)(str[i] - 'a' + 1) * numR) % M;
        ans %= M;
        numR = (numR * r) % M;
    }
    
    cout << ans;
    
    return 0;
}

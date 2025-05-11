#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int r = 31;
    int M = 1234567891;
    
    int l;
    cin >> l;
    
    string str;
    cin >> str;
    
    int ans = 0;
    
    for(int i=0; i<l; i++){
        ans += (str[i] - 'a' + 1) * pow(r, i);
        ans %= M;
    }
    
    cout << ans;
    
    return 0;
}

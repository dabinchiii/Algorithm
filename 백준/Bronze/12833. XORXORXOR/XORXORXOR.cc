#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    int ans = a;
    
    if(c % 2) ans ^= b;
    
    cout << ans;
    
    return 0;
}

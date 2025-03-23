#include <iostream>
#include <bitset>
#include <typeinfo>

using namespace std;

typedef bitset<10> bit;

int sumA, sumB;
int ans;

void solve(){
    bit a = bit(sumA);
    bit b = bit(sumB);
    
    auto c = a ^ b;

    ans = static_cast<int>(c.to_ulong());
    
    return;
}

int main(){
    cin >> sumA >> sumB;
    solve();
    cout << ans;

    return 0;
}

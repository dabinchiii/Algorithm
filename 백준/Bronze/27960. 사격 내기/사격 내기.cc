#include <iostream>
#include <bitset>
#include <typeinfo>

using namespace std;

typedef bitset<10> bit;

int sumA, sumB;
int ans;

void solve(){
    ans = static_cast<int>((bit(sumA) ^ bit(sumB)).to_ulong());
    
    return;
}

int main(){
    cin >> sumA >> sumB;
    solve();
    cout << ans;

    return 0;
}

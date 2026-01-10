#include <iostream>

using namespace std;

int main(){
    int N, a, b;
    cin >> N >> a >> b;
    --a; --b;
    
    int cnt = 1;
    while(a >> cnt != b >> cnt) ++cnt;
    
    cout << cnt;
    
    return 0;
}

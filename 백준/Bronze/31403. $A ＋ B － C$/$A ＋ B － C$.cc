#include <iostream>

using namespace std;

int main() {
    
    int a, b, c;
    
    cin >> a >> b >> c;
    
    int ans1 = a + b - c;
    int ans2 = stoi(to_string(a) + to_string(b)) - c;
    
    cout << ans1 << endl << ans2;
    
    
    return 0;
}

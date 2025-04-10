#include <iostream>

using namespace std;

int main(){
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    
    int t = 0, f = 0, w = 0;
    while(t < 24){
        if(f + a > m){ // 쉰다
            f -= c;
            f = max(0, f);
        }
        else{ // 일한다
            f += a;
            w += b;
        }
        t++;
    }
    
    cout << w;
    
    return 0;
}

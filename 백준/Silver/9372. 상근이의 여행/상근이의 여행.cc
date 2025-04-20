#include <iostream>

using namespace std;

int n, q;

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n >> q;
        
        int a, b;
        for(int i=0; i<q; i++){
            cin >> a >> b;
        }

        cout << n - 1 << '\n'; // 항상 연결 그래프를 이루므로..
    }
    
    return 0;
}

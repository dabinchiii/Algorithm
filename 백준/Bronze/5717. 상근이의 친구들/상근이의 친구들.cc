#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, f;

    while(1){
        cin >> m >> f;
        if(m == 0 && f == 0) break;
        cout << m + f << '\n';
    }

    return 0;
}

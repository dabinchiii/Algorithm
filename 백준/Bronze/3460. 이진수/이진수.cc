#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n;
        cin >> n;

        int pos = 0;
        while(n > 0){
            if(n % 2 == 1) cout << pos << ' ';
            n /= 2;
            pos++;
        }
        cout << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n, k;
        cin >> n >> k;

        int cnt, Answer = 0;
        for(int i=0; i<n; i++){
            cin >> cnt;
            Answer += cnt / k;
        }

        cout << Answer << '\n';
    }

    return 0;
}

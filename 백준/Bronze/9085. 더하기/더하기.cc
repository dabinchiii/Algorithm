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

        int num, sum = 0;
        for(int i=0; i<n; i++){
            cin >> num;
            sum += num;
        }

        cout << sum << '\n';
    }


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int y = 0, m = 0;
    int call;
    for(int i=0; i<n; i++){
        cin >> call;
        call++;

        y += (call / 30 + (call % 30 > 0 ? 1 : 0)) * 10;
        m += (call / 60 + (call % 60 > 0 ? 1 : 0)) * 15;
    }

    if(y <= m) cout << "Y ";
    if(y >= m) cout << "M ";
    cout << min(y, m);

    return 0;
}

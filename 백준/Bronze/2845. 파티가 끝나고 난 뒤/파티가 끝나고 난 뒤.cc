#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, p;
    cin >> l >> p;

    int total = l * p;

    int num;
    for(int i=0; i<5; i++){
        cin >> num;
        cout << num - total << ' ';
    }

    return 0;
}

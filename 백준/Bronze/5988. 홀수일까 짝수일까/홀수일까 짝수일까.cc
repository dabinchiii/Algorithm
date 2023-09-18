#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string num;
    for(int i=0; i<n; i++){
        cin >> num;
        cout << ((num[num.length()-1] - '0') % 2 == 0 ? "even" : "odd") << '\n';
    }
    return 0;
}

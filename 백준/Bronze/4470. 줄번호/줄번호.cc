#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string flush;
    getline(cin, flush);

    string str;
    for(int i=1; i<=n; i++){
        getline(cin, str);
        cout << i << ". " << str << '\n';
    }

    return 0;
}

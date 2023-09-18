#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=m-1; j>=0; j--){
            cout << str[j];
        }
        cout << '\n';
    }

    return 0;
}

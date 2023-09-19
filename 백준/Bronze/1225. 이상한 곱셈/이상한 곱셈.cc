#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    long long Answer = 0;
    for(int i=0; i<a.length(); i++){
        for(int j=0; j<b.length(); j++){
            Answer += (a[i] - '0') * (b[j] - '0');
        }
    }

    cout << Answer;

    return 0;
}

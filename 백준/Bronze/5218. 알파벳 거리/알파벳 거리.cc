#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string str1, str2;
    for(int i=0; i<n; i++){
        cin >> str1 >> str2;

        cout << "Distances:";
        for(int i=0; i<str1.length(); i++){

            cout << ' ' << (str2[i] + 26 - str1[i]) % 26;
        }
        cout << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> m;
    int cnt = 0;

    string str;
    while(true){
        getline(cin, str);
        if(str == "") break;
        m[str]++;
        cnt++;
    }

    cout << fixed;
    cout.precision(4);
    for(auto it : m){
        cout << it.first << ' ';
        cout << ((double)it.second / (double)cnt) * 100 << '\n';
    }

    return 0;
}

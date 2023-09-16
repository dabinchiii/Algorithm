#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> m;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;

        int dotIdx = -1;
        for(int i=str.length() - 1; i>=0; i--){
            if(str[i] == '.'){
                dotIdx = i;
                break;
            }
        }
        string ex = str.substr(dotIdx + 1);
        m[ex]++;
    }

    for(auto it=m.begin(); it!=m.end(); it++){
        cout << it->first << " " << it->second << '\n';
    }

    return 0;
}

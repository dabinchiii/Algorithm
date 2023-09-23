#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> s;
    string name, state;
    for(int i=0; i<n; i++){
        cin >> name >> state;

        if(state == "enter"){
            s.insert(name);
        }
        else{
            auto it = s.find(name);
            if(it != s.end()) s.erase(it);
        }
    }

    for(auto it=s.rbegin(); it!=s.rend(); it++){
        cout << *it << '\n';
    }

    return 0;
}

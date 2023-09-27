#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int na, nb;
    cin >> na >> nb;

    set<int> s;
    int num;
    for(int i=0; i<na; i++){
        cin >> num;
        s.insert(num);
    }
    for(int i=0; i<nb; i++){
        cin >> num;
        auto idx = s.find(num);
        if(idx != s.end()){
            s.erase(idx);
        }
    }

    cout << s.size() << '\n';
    for(auto it=s.begin(); it!=s.end(); it++){
        cout << *it << ' ';
    }
    return 0;
}

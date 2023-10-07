#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> m;
    string name;
    for(int i=0; i<n; i++){
        cin >> name;
        m[name]++;
    }
    for(int i=0; i<n-1; i++){
        cin >> name;
        m[name]--;
    }

    string Answer = "";
    for(auto x : m){
        if(x.second > 0){
            Answer = x.first;
            break;
        }
    }

    cout << Answer;

    return 0;
}

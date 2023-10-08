#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> s;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;

        vector<char> v((int)str.length());
        int j=0;
        for(char c : str){
            v[j++] = c;
        }
        sort(v.begin(), v.end());

        string sorted = "";
        for(char c : v){
            sorted += c;
        }

        s.insert(sorted);
    }

    cout << (int)s.size();

    return 0;
}

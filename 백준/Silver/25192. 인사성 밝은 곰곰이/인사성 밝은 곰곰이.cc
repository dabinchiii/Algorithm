#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> s;
    int Answer = 0;

    string line;
    for(int i=0; i<n; i++){
        cin >> line;

        if(line == "ENTER"){
            Answer += s.size();
            s.clear();
        }
        else{
            s.insert(line);
        }
    }
    Answer += s.size();

    cout << Answer;

    return 0;
}

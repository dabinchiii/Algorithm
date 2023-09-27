#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> rainbow;
    rainbow.insert("ChongChong");

    int n;
    cin >> n;

    string a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;

        if(rainbow.find(a) != rainbow.end()){
            rainbow.insert(b);
        }
        else if(rainbow.find(b) != rainbow.end()){
            rainbow.insert(a);
        }
    }

    cout << rainbow.size();

    return 0;
}

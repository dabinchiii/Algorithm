#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string Answer = "";

    for(int i=n/4; i>=1; i--){
        Answer += "long ";
    }
    Answer += "int";

    cout << Answer;

    return 0;
}

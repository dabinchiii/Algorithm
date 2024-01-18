#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string str, Answer;
    for(int i=0; i<n; i++){
        cin >> str;

        Answer = "";
        for(int j=0; j<str.length(); j++){
            Answer.push_back(tolower(str[j]));
        }
        cout << Answer << '\n';
    }

    return 0;
}

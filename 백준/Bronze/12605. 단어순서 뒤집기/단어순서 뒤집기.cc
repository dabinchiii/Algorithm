#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string flush;
    getline(cin, flush);

    string str;
    for(int i=1; i<=n; i++){
        getline(cin, str);
        str += " ";

        vector<string> words;
        int left = 0;
        for(int j=0; j<str.length(); j++){
            if(str[j] != ' ') continue;

            string sub = str.substr(left, j-left);
            words.push_back(sub);

            left = j + 1;
        }

        cout << "Case #" << i << ": ";
        for(auto it=words.rbegin(); it!=words.rend(); it++){
            cout << *it << ' ';
        }
        cout << '\n';
    }

    return 0;
}

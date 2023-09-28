#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;

        list<char> lt;
        auto cursor = lt.begin();

        for(int j=0; j<str.length(); j++){
            if(str[j] == '<'){
                if(cursor != lt.begin()) cursor--;
            }
            else if(str[j] == '>'){
                if(cursor != lt.end()) cursor++;
            }
            else if(str[j] == '-'){
                if(cursor != lt.begin()) cursor = lt.erase(--cursor);
            }
            else{
                cursor = lt.insert(cursor, str[j]);
                cursor++;
            }
        }

        for(char ch : lt){
            cout << ch;
        }
        cout << '\n';
    }

    return 0;
}

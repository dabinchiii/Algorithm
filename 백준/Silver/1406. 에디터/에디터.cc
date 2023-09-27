#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    list<char> lt;
    for(int i=0; i<str.length(); i++){
        lt.push_back(str[i]);
    }

    int m;
    cin >> m;

    auto cursor = lt.end();

    char oper;
    for(int i=0; i<m; i++){
        cin >> oper;
        if(oper == 'L'){
            if(cursor != lt.begin()) cursor--;
        }
        else if(oper == 'D'){
            if(cursor != lt.end()) cursor++;
        }
        else if(oper == 'B'){
            if(cursor != lt.begin()){
                lt.erase(prev(cursor, 1));
            }
        }
        else if(oper == 'P'){
            char ch;
            cin >> ch;

            lt.insert(cursor, ch);
        }
    }

    for(auto it=lt.begin(); it!=lt.end(); it++){
        cout << *it;
    }

    return 0;
}

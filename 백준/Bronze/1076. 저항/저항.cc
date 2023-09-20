#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> table;
    table["black"] = 0;
    table["brown"] = 1;
    table["red"] = 2;
    table["orange"] = 3;
    table["yellow"] = 4;
    table["green"] = 5;
    table["blue"] = 6;
    table["violet"] = 7;
    table["grey"] = 8;
    table["white"] = 9;

    string c[3];
    for(int i=0; i<3; i++){
        cin >> c[i];
    }

    long long Answer = 10 * table[c[0]] + table[c[1]];
    Answer *= pow(10, table[c[2]]);
    cout << Answer;

    return 0;
}

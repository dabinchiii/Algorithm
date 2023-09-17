#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> x, y;
    int numX, numY;
    for(int i=0; i<3; i++){
        cin >> numX >> numY;
        x[numX]++;
        y[numY]++;
    }

    auto it = x.begin();
    if(it->second != 1) it++;
    cout << it->first << ' ';

    it = y.begin();
    if(it->second != 1) it++;
    cout << it->first;

    return 0;
}

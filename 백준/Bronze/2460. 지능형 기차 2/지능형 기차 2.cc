#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int curr = 0, maxValue = 0;
    int getOff, getIn;
    for(int i=0; i<10; i++){
        cin >> getOff >> getIn;

        curr -= getOff;
        maxValue = max(maxValue, curr);
        curr += getIn;
        maxValue = max(maxValue, curr);
    }

    cout << maxValue;

    return 0;
}

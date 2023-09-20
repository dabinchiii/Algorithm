#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int curr = 0, maxValue = -1;
    int getOff, getOn;

    for(int i=0; i<4; i++){
        cin >> getOff >> getOn;

        curr -= getOff;
        maxValue = max(maxValue, curr);
        curr += getOn;
        maxValue = max(maxValue, curr);
    }

    cout << maxValue;

    return 0;
}

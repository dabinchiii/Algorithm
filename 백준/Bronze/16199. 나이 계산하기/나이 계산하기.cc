#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int birthY, birthM, birthD;
    cin >> birthY >> birthM >> birthD;

    int currY, currM, currD;
    cin >> currY >> currM >> currD;

    int diffY, diffM, diffD;
    diffY = currY - birthY;
    diffM = currM - birthM;
    diffD = currD - birthD;

    if(diffD < 0) diffM--;
    if(diffM < 0) diffY--;

    cout << diffY  << '\n';
    cout << currY - birthY + 1<< '\n';
    cout << currY - birthY;

    return 0;
}

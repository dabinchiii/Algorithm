#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    vector<int> len(6);
    int firstMainValue = -1, firstMainIndex; // w or h
    int dir;
    for(int i=0; i<6; i++){
        cin >> dir >> len[i];
        if(len[i] > firstMainValue){
            firstMainValue = len[i];
            firstMainIndex = i;
        }
    }

    int secondMainValue, secondMainIndex;
    secondMainIndex = (firstMainIndex + 1) % 6;
    secondMainValue = len[secondMainIndex];

    if(secondMainValue < len[(firstMainIndex - 1 + 6) % 6]){
        secondMainIndex = (firstMainIndex - 1 + 6) % 6;
        secondMainValue = len[secondMainIndex];
    }

    int firstSubIndex = (firstMainIndex + 3) % 6;
    int secondSubIndex = (secondMainIndex + 3) % 6;

    int area = firstMainValue * secondMainValue;
    area -= len[firstSubIndex] * len[secondSubIndex];

    cout << area * k;

    return 0;
}

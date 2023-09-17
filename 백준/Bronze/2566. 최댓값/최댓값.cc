#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int maxValue = -1, num;
    pair<int, int> maxPos;

    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cin >> num;
            if(num > maxValue){
                maxValue = num;
                maxPos = {i, j};
            }
        }
    }

    cout << maxValue << '\n';
    cout << maxPos.first << ' ' << maxPos.second;

    return 0;
}

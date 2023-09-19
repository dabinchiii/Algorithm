#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n;
        cin >> n;

        int value, maxValue = -1;
        string player, maxPlayer = "";

        for(int i=0; i<n; i++){
            cin >> value >> player;
            if(value > maxValue){
                maxValue = value;
                maxPlayer = player;
            }
        }

        cout << maxPlayer << '\n';
    }

    return 0;
}

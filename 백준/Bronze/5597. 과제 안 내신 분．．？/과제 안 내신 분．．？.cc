#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> arr(31, false);
    int num;
    for(int i=0; i<28; i++){
        cin >> num;
        arr[num] = true;
    }

    for(int i=1; i<=30; i++){
        if(!arr[i]) cout << i << endl;
    }

    return 0;
}

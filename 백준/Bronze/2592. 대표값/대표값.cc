#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, sum = 0;
    map<int, int> m;
    for(int i=0; i<10; i++){
        cin >> num;
        m[num]++;
        sum += num;
    }
    int maxValue = -1, maxNum;
    for(auto it : m){
        if(it.second > maxValue){
            maxValue = it.second;
            maxNum = it.first;
        }
    }

    cout << sum / 10 << '\n' << maxNum;
    return 0;
}

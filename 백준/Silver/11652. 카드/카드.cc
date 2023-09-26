#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<long long, int> m;
    long long num;
    for(int i=0; i<n; i++){
        cin >> num;
        m[num]++;
    }

    int maxValue = -1;
    long long maxNum = -1;
    for(auto it=m.begin(); it!=m.end(); it++){
        if(it->second == maxValue){
            maxNum = min(maxNum, it->first);
        }
        else if(it->second > maxValue){
            maxValue = it->second;
            maxNum = it->first;
        }
    }

    cout << maxNum;

    return 0;
}

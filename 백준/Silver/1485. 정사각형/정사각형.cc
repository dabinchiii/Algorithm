#include <iostream>
#include <algorithm>

using namespace std;

long long calc(pair<int, int> p1, pair<int, int> p2){
    long long dr = p1.first - p2.first;
    long long dc = p1.second - p2.second;
    return dr * dr + dc * dc;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int TC;
    cin >> TC;
    for(int tc=1; tc<=TC; tc++){
        pair<int, int> p[4];
        for(int i=0; i<4; i++){
            cin >> p[i].first >> p[i].second;
        }
        sort(p, p + 4);
        
        vector<long long> arr;
        for(int i=0; i<4; i++){
            for(int j=i + 1; j<4; j++){
                arr.push_back(calc(p[i], p[j]));
            }
        }
        
        sort(arr.begin(), arr.end());
        
        bool result = true;
        if(arr[0] != arr[3]) result = false;
        if(arr[4] != arr[5]) result = false;
        if(arr[0] << 1 != arr[5]) result = false;
        
        cout << (result ? 1 : 0) << '\n';
    }
    
    return 0;
}

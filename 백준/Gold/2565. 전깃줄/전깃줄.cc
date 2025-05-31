#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> arr;

int solve(){
    sort(arr.begin(), arr.end());
    
    vector<int> v;
    for(int i=0; i<n; i++){
        int curr = arr[i].second;
        
        if(v.empty() || curr > v.back()){
            v.push_back(curr);
        }
        else{
            int idx = (int)(lower_bound(v.begin(), v.end(), curr) - v.begin());
            v[idx] = curr;
        }
    }
    
    return (n - (int)v.size());
}
int main(){
    cin >> n;
    
    int a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        arr.push_back({a, b});
    }
    
    cout << solve();
    
    return 0;
}

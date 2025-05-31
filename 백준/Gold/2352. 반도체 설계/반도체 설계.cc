#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[40000];

int solve(){
    vector<int> v;
    
    for(int i=0; i<n; i++){
        int curr = arr[i];
        
        if(v.empty() || curr > v.back()){
            v.push_back(curr);
        }
        else{
            int idx = (int)(lower_bound(v.begin(), v.end(), curr) - v.begin());
            v[idx] = curr;
        }
    }
    
    return (int)v.size();
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    cout << solve();
    
    return 0;
}

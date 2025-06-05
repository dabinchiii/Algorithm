#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[200];
int ans;

void solve(){
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
    
    ans = n - (int)v.size();
    
    return;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    solve();
    
    cout << ans;
    
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> arr;
int maxNum;


void solve(){
    sort(arr.begin(), arr.end());
    
    vector<pair<int, int>> v; // {value, idx}
    vector<int> before(n, -1);
    
    for(int i=0; i<n; i++){
        int currIdx = i;
        int currVal = arr[i].second;
        
        if(v.empty() || currVal > v.back().first){
            if(!v.empty()){
                before[i] = v.back().second; // idx
            }
            
            v.push_back({currVal, currIdx});
        }
        else{
            // lower_bound(<#ForwardIterator first#>, <#ForwardIterator last#>, <#const Tp &value#>, <#Compare comp#>)
            
            auto it = lower_bound(v.begin(), v.end(), make_pair(currVal, currIdx), [](const auto& a, const auto& b){
                return a.first < b.first;
            });
            int idx = (int)(it - v.begin());
            
            if(idx - 1 >= 0){
                before[currIdx] = v[idx - 1].second;
            }
            
            v[idx] = {currVal, currIdx};
        }
        
    }
    
    vector<bool> visited(n + 1, false);
    int currIdx = v.back().second;
    while(currIdx != -1){
        visited[currIdx] = true;
        currIdx = before[currIdx];
    }
//    
    cout << n - (int)v.size() << '\n';
    for(int i=0; i<n; i++){
        if(!visited[i]) cout << arr[i].first << '\n';
    }
    
    return;
}

int main(){
    cin >> n;
    
    int a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        arr.push_back({a, b});
        
        maxNum = max(maxNum, max(a, b));
    }
    
    solve();
    
    return 0;
}

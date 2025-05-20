#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
pair<int, int> arr[1000]; // {남은 일수, 점수}
int ans;

bool comp(pair<int, int> &a, pair<int, int> &b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}
void solve(){
    sort(arr, arr + n, comp); // 점수 높은 순 -> 남은 일수 적은 순 정렬
    
    int maxD = -1;
    for(int i=0; i<n; i++) maxD = max(maxD, arr[i].first);
    
    vector<int> plan(maxD + 1, -1);
    for(int i=0; i<n; i++){
        int t = arr[i].first;
        
        while(t > 0){
            if(plan[t] == -1){
                plan[t] = i;
                break;
            }
            t--;
        }
    }
    
    for(int i=1; i<=maxD; i++){
        int curr = plan[i];
        
        if(curr == -1) continue;
        ans += arr[curr].second;
    }
    
    return;
}

int main(){
    cin >> n;
    
    int d, w;
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

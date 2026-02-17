#include <iostream>
#include <deque>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N, D;
long long arr[MAX_N + 1];
long long ans = -1000000001;

void solve(){
    deque<pair<int, long long>> dq; // {idx, acc}
    
    dq.push_back({0, 0ll});
    
    for(int i=1; i<=N; i++){
        while(!dq.empty() && i - dq.front().first > D) dq.pop_front();
        
        long long acc = max(arr[i], dq.front().second + arr[i]);
        ans = max(ans, acc);
        
        while(!dq.empty() && dq.back().second <= acc) dq.pop_back();
        dq.push_back({i, acc});
    }
    		
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> D;
    
    for(int i=1; i<=N; i++) cin >> arr[i];
    
    solve();
    
    cout << ans;
    
    return 0;
}

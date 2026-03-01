#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N;
pair<int, int> lec[MAX_N];
int ans;

void solve(){
    sort(lec, lec + N);
    
    priority_queue<int> pq;
    for(int i=0; i<N; i++){
        if(!pq.empty() && -pq.top() <= lec[i].first) pq.pop();
        pq.push(-lec[i].second);
    }
    
    ans = (int)pq.size();
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    int no;
    for(int i=0; i<N; i++) cin >> no >> lec[i].first >> lec[i].second;
    
    solve();
    cout << ans;
    
    return 0;
}

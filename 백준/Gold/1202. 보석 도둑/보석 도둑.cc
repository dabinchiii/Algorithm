#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 300000
#define MAX_K 300000

using namespace std;

int N, K;
pair<int, int> gem[MAX_N];
int bag[MAX_K];
long long ans;

void solve(){
    sort(bag, bag + K); // 오름차순
    sort(gem, gem + N); // 보석 무게 기준 내림차순
    
    priority_queue<int> pq;
    
    int idx = 0;
    for(int i=0; i<K; i++){
        while(idx < N && gem[idx].first <= bag[i]) pq.push(gem[idx++].second);
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    
    for(int i=0; i<N; i++) cin >> gem[i].first >> gem[i].second;
    for(int i=0; i<K; i++) cin >> bag[i];
    
    solve();
    
    cout << ans;
    
    return 0;
}

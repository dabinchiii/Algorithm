#include <iostream>
#include <queue>

using namespace std;

void solve(){
    int K;
    long long ans = 0;
    priority_queue<long long> pq;
    
    cin >> K;
    int x;
    for(int i=0; i<K; i++){
        cin >> x;
        pq.push(-x);
    }
    
    while(pq.size() > 1){
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    
    cout << -ans << '\n';
    
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        solve();
    }
    
    return 0;
}

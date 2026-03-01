#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX_N 60
#define MOD 1000000007

using namespace std;

typedef unsigned long long ull;

void solve(){
    int N;
    cin >> N;
    
    priority_queue<ull, vector<ull>, greater<ull>> pq;
    
    ull s;
    for(int i=0; i<N; i++){
        cin >> s;
        pq.push(s);
    }
    
    ull ans = 1, a, b, curr;
    while(pq.size() > 1){
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        
        curr = a * b;
        pq.push(curr);
        
        ans *= curr % MOD;
        ans %= MOD;
    }
    
    cout << ans << '\n';
    
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

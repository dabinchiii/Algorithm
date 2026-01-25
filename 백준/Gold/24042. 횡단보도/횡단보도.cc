#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100000
#define INF 70000000000

using namespace std;

typedef long long ll;

int N, M;
vector<pair<int, int>> g[MAX_N + 1];
ll ans;

void solve(){
    priority_queue<pair<ll, int>> pq;
    vector<ll> dist(N + 1, INF);
    
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()){
        ll currT = -pq.top().first;
        int currV = pq.top().second;
        pq.pop();
        
        if(currT > dist[currV]) continue;
        
        for(auto nxt : g[currV]){
            int nxtV = nxt.first;
            ll nxtT = (currT / M) * M + nxt.second + 1;
            if(nxtT < currT) nxtT += M;
                
            if(nxtT < dist[nxtV]){
                dist[nxtV] = nxtT;
                pq.push({-nxtT, nxtV});
            }
        }
    }

    
    ans = dist[N];
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

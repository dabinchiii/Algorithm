#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100000
#define INF 10000000000

using namespace std;

int n, m, k;
vector<pair<int, int>> g[MAX_N + 1]; // g[0]: 더미
int ansV;
long long ansDist;

void solve(){
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>> q;
    
    dist[0] = 0;
    q.push({0, 0});
    
    while(!q.empty()){
        long long currDist = -q.top().first;
        int currV = q.top().second;
        q.pop();
        
        if(currDist > dist[currV]) continue;
        
        for(auto nxt : g[currV]){
            int nxtV = nxt.first;
            long long nxtDist = currDist + nxt.second;
            
            if(nxtDist < dist[nxtV]){
                dist[nxtV] = nxtDist;
                q.push({-nxtDist, nxtV});
            }
        }
    }
    
    long long maxVal = -1;
    int maxV = -1;
    for(int i=1; i<=n; i++){
        if(dist[i] > maxVal){
            maxVal = dist[i];
            maxV = i;
        }
    }
    ansV = maxV;
    ansDist = maxVal;
    
    return;
}

int main(){
    cin >> n >> m >> k;
    
    int u, v, c;
    for(int i=0; i<m; i++){
        cin >> u >> v >> c;
        
        g[v].push_back({u, c});
    }
    
    
    for(int i=0; i<k; i++){
        cin >> u;
        
        g[0].push_back({u, 0});
    }
    
    solve();
    
    cout << ansV << endl << ansDist;
    
    return 0;
}

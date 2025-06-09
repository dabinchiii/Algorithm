#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000
#define INF 1000000000

using namespace std;

int n, m, x, y;
vector<pair<int, int>> g[MAX_N];
int ans;

void solve(){
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    int cnt = 0;
    
    dist[y] = 0;
    visited[y] = true;
    cnt++;
    
    // y에서 출발하는 최소 비용 구하기
    int currV = y;
    while(cnt < n){
        
        for(auto nxt : g[currV]){
            int nxtV = nxt.first;
            int nxtDist = nxt.second;
            
            dist[nxtV] = min(dist[nxtV], dist[currV] + nxtDist);
        }
        
        // 다음 노드 선택
        int minVal = INF, minV = -1;
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            
            if(dist[i] < minVal){
                minVal = dist[i];
                minV = i;
            }
        }
        currV = minV;
        visited[currV] = true;
        cnt++;
    }
    
    for(int i=0; i<n; i++){
        dist[i] *= 2; // 왕복거리
    }
    
    sort(dist.begin(), dist.end());
    
    if(dist[n - 1] > x){
        ans = -1;
        return;
    }
    
    int curr = 0;
    ans++;
    for(int i=0; i<n; i++){
        if(curr + dist[i] <= x){
            curr += dist[i];
        }
        else{
            ans++;
            curr = dist[i];
        }
    }
    
    return;
}

int main(){
    cin >> n >> m >> x >> y;
    
    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

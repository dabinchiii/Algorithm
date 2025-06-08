#include <iostream>
#include <algorithm>

#define MAX_N 10000
#define INF 10000000001

using namespace std;

int n, m, s, e;
vector<pair<int, long long>> g[MAX_N + 1];
//long g[MAX_N + 1][MAX_N + 1];
long ans;

void solve(){
    vector<long long> maxW(n + 1, 0);
    vector<bool> visited(n + 1, false);
    int cnt = 0;
    
    int currV = s;
    maxW[s] = INF;
    visited[s] = true;
    cnt++;
    
    while(cnt < n){
        for(auto curr : g[currV]){
            int nxtV = curr.first;
            long long nxtW = curr.second;
            
            if(visited[nxtV]) continue;
//            if(g[currV][i] == 0 || visited[i]) continue;
            
//            int nxtV = i;
//            long nxtW = g[currV][nxtV];
            
            maxW[nxtV] = max(maxW[nxtV], min(maxW[currV], nxtW));
            
        }
        
        // 다음 방문할 노드 결정 (방문하지 않은 노드 중, maxW 값 가장 큰 노드)
        int nxt = -1;
        long maxVal = -1;
        for(int i=1; i<=n; i++){
            if(visited[i]) continue;
            
            if(maxW[i] > maxVal){
                maxVal = maxW[i];
                nxt = i;
            }
        }
        
        // currV 업데이트
        currV = nxt;
        visited[currV] = true;
        cnt++;
    }
    
    ans = maxW[e];
    
    return;
}

int main(){
    cin >> n >> m;
    
    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        
//        if(c > g[a][b]){
//            g[a][b] = g[b][a] = c;
//        }
        
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    cin >> s >> e;
    
    solve();
    
    cout << ans;
    
    return 0;
}

//4 4
//1 2 6
//1 3 4
//1 4 3
//3 4 5
//1 4



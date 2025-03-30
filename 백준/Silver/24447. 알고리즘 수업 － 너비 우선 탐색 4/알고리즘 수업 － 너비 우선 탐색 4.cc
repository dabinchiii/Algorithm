#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, r;
vector<int> g[100001];
vector<long long> t(100001, 0), d(100001, -1);

void bfs(int start){
    queue<pair<int, int>> q;
    vector<bool> visited(n + 1, false);
    
    visited[start] = true;
    q.push({start, 0});
    d[start] = 0;
    
    int cnt = 0;
    t[start] = ++cnt;
    
    while(!q.empty()){
        int currNode = q.front().first;
        int currDepth = q.front().second;
        q.pop();
        
        for(int nxtNode : g[currNode]){
            if(visited[nxtNode]) continue;
            
            t[nxtNode] = ++cnt;
            d[nxtNode] = currDepth + 1;
            
            visited[nxtNode] = true;
            q.push({nxtNode, currDepth + 1});
        }
        
    }
    
    return;
}

int main(){
    cin >> n >> m >> r;
    
    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++){
        sort(g[i].begin(), g[i].end());
    }
    bfs(r);
    
    long long ans = 0;
    for(int i=1; i<=n; i++){
        ans += t[i] * d[i];
    }
    
    cout << ans;
    
    return 0;
}

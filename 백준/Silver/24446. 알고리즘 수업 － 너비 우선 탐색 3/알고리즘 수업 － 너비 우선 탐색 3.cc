#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, r;
vector<int> g[100001];
vector<int> ans(100001, -1);

void bfs(int start){
    queue<pair<int, int>> q;
    vector<bool> visited(n + 1, false);
    
    visited[start] = true;
    q.push({start, 0});
    ans[start] = 0;
    
    while(!q.empty()){
        int currNode = q.front().first;
        int currDepth = q.front().second;
        q.pop();
        
        for(int nxtNode : g[currNode]){
            if(visited[nxtNode]) continue;
            
            visited[nxtNode] = true;
            q.push({nxtNode, currDepth + 1});
            ans[nxtNode] = currDepth + 1;
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
    
    bfs(r);
    
    for(int i=1; i<=n; i++){
        cout << ans[i] << '\n';
    }
    
    return 0;
}

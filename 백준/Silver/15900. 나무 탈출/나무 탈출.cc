#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 500000

using namespace std;

int N;
vector<int> g[MAX_N + 1];

// 각각의 말들은 {처음 위치한 리프 노드의 depth}번씩 움질일 수 있다.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    int u, v;
    for(int i=0; i<N-1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    
    queue<int> q;
    vector<bool> visited(N + 1, false);
    vector<int> depth(N + 1);
    
    int sum = 0; // 모든 리프 노드들의 depth 합
    
    q.push(1);
    visited[1] = true;
    depth[1] = 0;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        int cnt = 0; // 자식 수
        for(int nxt : g[curr]){
            if(visited[nxt]) continue;
            ++cnt;
            
            visited[nxt] = true;
            q.push(nxt);
            depth[nxt] = depth[curr] + 1;
        }
        
        if(cnt == 0){ // curr이 리프였다
            sum += depth[curr];
        }
    }
    
    cout << (sum % 2 ? "Yes" : "No");
    
    return 0;
}

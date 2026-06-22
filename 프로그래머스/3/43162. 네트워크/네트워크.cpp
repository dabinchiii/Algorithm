#include <vector>
#include <queue>

#define MAX_N 200

using namespace std;

int N;
vector<vector<int>> g;
bool visited[MAX_N];
int ans;

void bfs(int start){
    queue<int> q;
    
    ++ans;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int nxt=0; nxt<N; nxt++){
            if(nxt == curr || g[curr][nxt] == 0) continue;
            if(visited[nxt]) continue;
            
            q.push(nxt);
            visited[nxt] = true;
        }
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    N = n;
    g = computers;
    
    for(int i=0; i<N; i++){
        if(!visited[i]) bfs(i);
    }
    
    return ans;
}
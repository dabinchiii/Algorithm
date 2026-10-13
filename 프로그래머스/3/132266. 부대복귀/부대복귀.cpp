#include <vector>
#include <queue>

#define MAX_N 100000

using namespace std;

vector<int> g[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1];

void bfs(int start){
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    visited[start] = true;
    
    while(!q.empty()){
        int currV = q.front();
        q.pop();
        
        for(int nxt : g[currV]){
            if(visited[nxt]) continue;
            
            visited[nxt] = true;
            dist[nxt] = dist[currV] + 1;
            q.push(nxt);
        }
        
    }
    
    
    return;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    for(vector<int> curr : roads){
        g[curr[0]].push_back(curr[1]);
        g[curr[1]].push_back(curr[0]);
    }    
    
    bfs(destination);
    
    vector<int> ans(sources.size());
    for(int i=0; i<sources.size(); i++){
        ans[i] = visited[sources[i]] ? dist[sources[i]] : -1;
    }
    
    return ans;
}
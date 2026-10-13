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
    
    vector<int> ans;
    for(int curr : sources){
        if(!visited[curr]) ans.push_back(-1);
        else ans.push_back(dist[curr]);
    }
    
    return ans;
}
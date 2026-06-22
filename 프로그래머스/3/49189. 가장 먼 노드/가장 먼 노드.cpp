#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 20000

using namespace std;

vector<int> g[MAX_N + 1];
queue<pair<int, int>> q;
bool visited[MAX_N + 1];
int maxLen, ans;

int solution(int n, vector<vector<int>> edge) {
    for(auto curr : edge){
        g[curr[0]].push_back(curr[1]);
        g[curr[1]].push_back(curr[0]);
    }
    
    q.push({1, 0});
    visited[1] = true;
    
    while(!q.empty()){
        int currV = q.front().first;
        int currLen = q.front().second;
        q.pop();
        
        if(currLen > maxLen){
            maxLen = currLen;
            ans = 0;
        }
        
        ++ans;
        
        for(int nxt : g[currV]){
            if(visited[nxt]) continue;
            q.push({nxt, currLen + 1});
            visited[nxt] = true;
        }
    }
    
    return ans;
}
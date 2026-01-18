#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1000

using namespace std;

int N, K;
vector<pair<int, int>> g[MAX_N], tree[MAX_N];
int ansMinTotal, ansMaxCost;

void mst(){
    int cost = 0, cnt = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<bool> visited(N, false);
    
    pq.push({0, {0, 0}});
    
    while(!pq.empty()){
        if(cnt >= N) break;
        
        int currW = -pq.top().first;
        int currV = pq.top().second.first;
        int prevV = pq.top().second.second;
        pq.pop();
        
        if(visited[currV]) continue;
        
        visited[currV] = true;
        ++cnt;
        cost += currW;
        tree[prevV].push_back({currV, currW});
        tree[currV].push_back({prevV, currW});
        
        for(auto nxt : g[currV]){
            if(!visited[nxt.first]) pq.push({-nxt.second, {nxt.first, currV}});
        }
    }
    
    ansMinTotal = cost;
    
    return;
}
int bfs1(int start){ // start에서 가장 먼 노드 찾는다.
    queue<pair<int, int>> q;
    vector<bool> visited(N, false);
    int maxDist = -1, maxV = -1;
    
    q.push({start, 0});
    visited[start] = true;
    
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        
        for(auto nxt : tree[curr.first]){
            if(visited[nxt.first]) continue;
            
            visited[nxt.first] = true;
            int ndist = curr.second + nxt.second;
            q.push({nxt.first, ndist});
            
            if(ndist > maxDist){
                maxDist = ndist;
                maxV = nxt.first;
            }
        }
    }
    
    return maxV;
}
int bfs2(int start){
    queue<pair<int, int>> q;
    vector<bool> visited(N, false);
    int maxDist = -1, maxV = -1;
    
    q.push({start, 0});
    visited[start] = true;
    
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        
        for(auto nxt : tree[curr.first]){
            if(visited[nxt.first]) continue;
            
            visited[nxt.first] = true;
            int ndist = curr.second + nxt.second;
            q.push({nxt.first, ndist});
            
            if(ndist > maxDist){
                maxDist = ndist;
                maxV = nxt.first;
            }
        }
    }
    
    return maxDist;
}

void lca(){
    int from = bfs1(0);
    ansMaxCost = bfs2(from);
    return;
}
void solve(){
    mst();
    lca();
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    
    int a, b, c;
    for(int i=0; i<K; i++){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    solve();
    
    cout << ansMinTotal << '\n' << ansMaxCost;
    
    return 0;
}

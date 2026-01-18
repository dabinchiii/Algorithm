#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1000

using namespace std;

struct edge{
    int w, v, prev;
    bool operator<(const edge& other) const{
        return w > other.w;
    }
};

int N, K;
vector<pair<int, int>> g[MAX_N], tree[MAX_N];
int ansMinTotal, ansMaxCost;

void mst(){
    int cost = 0, cnt = 0;
    priority_queue<edge> pq;
    vector<bool> visited(N, false);
    
    pq.push({0, 0, 0});
    
    while(!pq.empty()){
        if(cnt >= N) break;
        
        edge curr = pq.top();
        pq.pop();
        
        if(visited[curr.v]) continue;
        
        visited[curr.v] = true;
        ++cnt;
        cost += curr.w;
        tree[curr.prev].push_back({curr.v, curr.w});
        tree[curr.v].push_back({curr.prev, curr.w});
        
        for(auto nxt : g[curr.v]){
            if(!visited[nxt.first]) pq.push({nxt.second, nxt.first, curr.v});
        }
    }
    
    ansMinTotal = cost;
    
    return;
}
pair<int, int> bfs(int start){ // start에서 가장 먼 노드와 그 비용 찾는다.
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
    
    return {maxV, maxDist};
}

void dia(){ // mst 트리의 지름 구한다. 머리끄댕이
    int from = bfs(0).first;
    ansMaxCost = bfs(from).second;
    return;
}
void solve(){
    mst();
    dia();
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

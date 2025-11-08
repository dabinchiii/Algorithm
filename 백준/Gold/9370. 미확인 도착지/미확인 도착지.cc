#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 2000
#define MAX_T 100
#define INF 2000005

using namespace std;

struct qNode{
    int node, d;
    bool gh;
};
struct compare{
    bool operator()(qNode &a, qNode &b){
        if(a.d != b.d) return a.d < b.d; // d 오름차순
        return a.gh;
    }
};

int N, M, T;
int S, G, H;
vector<pair<int, int>> g[MAX_N + 1];
int dest[MAX_T];
vector<int> ans;

void solve(){
    priority_queue<qNode, vector<qNode>, compare> pq;
    vector<pair<int, bool>> dist(N + 1, {INF, false});
    
    pq.push({S, 0, false});
    dist[S].first = 0;
    
    while(!pq.empty()){
        qNode curr = pq.top();
        pq.pop();
        
        if(curr.d > dist[curr.node].first) continue;
        
        for(pair<int, int> nxt : g[curr.node]){
            int nnode = nxt.first;
            int nd = curr.d + nxt.second;
            bool ngh = curr.gh || ((curr.node == G && nnode == H) || (curr.node == H && nnode == G));
            
            if(nd < dist[nnode].first){
                dist[nnode] = {nd, ngh};
                pq.push({nnode, nd, ngh});
            }
            else if(nd == dist[nnode].first && ngh && !dist[nnode].second){ // 거리는 같은데 gh 지나온 경우
                dist[nnode].second = ngh;
                pq.push({nnode, nd, ngh});
            }
        }
    }
    
    for(int i=0; i<T; i++){
        if(dist[dest[i]].second) ans.push_back(dest[i]);
    }
    sort(ans.begin(), ans.end());
    
    return;
}

int main(){
    int TC;
    cin >> TC;
    for(int tc=1; tc<=TC; ++tc){
        cin >> N >> M >> T >> S >> G >> H;
        
        for(int i=1; i<=N; i++) g[i].clear();
        
        int a, b, d;
        for(int i=0; i<M; i++){
            cin >> a >> b >> d;
            g[a].push_back({b, d});
            g[b].push_back({a, d});
        }
        
        for(int i=0; i<T; i++){
            cin >> dest[i];
        }
        
        ans.clear();
        solve();
        
        for(int curr : ans) cout << curr << ' ';
        cout << '\n';
    }
    
    
    
    return 0;
}

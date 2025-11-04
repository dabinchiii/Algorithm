#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 16
#define INF 100000000

using namespace std;

struct qNode{
    int node, record, cost;
};
struct compare{
    bool operator()(qNode a, qNode b){
        return a.cost < b.cost;
    }
};

int N;
int w[MAX_N][MAX_N];
int ans;

void solve(){
    ans = INF;
    int start = 0;
    //priority_queue<qNode, vector<qNode>, compare> q;
    queue<qNode> q;
    int dist[MAX_N][(1 << (N + 1))];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<(1 << N); j++){
            dist[i][j] = INF;
        }
    }
    
    q.push({start, 1 << start, 0});
    dist[start][(1 << start)] = 0;
    
    while(!q.empty()){
        qNode curr = q.front();
        q.pop();
        
        if(dist[curr.node][curr.record] < curr.cost) continue;
        
        //cout << curr.cost << endl;
        
        if((curr.record == (1 << N) - 1) && w[curr.node][start] != 0){
            ans = min(ans, curr.cost + w[curr.node][start]);
            continue;
        }
        
        for(int nxt=0; nxt<N; nxt++){
            if(w[curr.node][nxt] == 0) continue;
            if((curr.record & (1 << nxt)) != 0) continue;
            
            int ncost = curr.cost + w[curr.node][nxt];
            int nrecord = curr.record | (1 << nxt);
            if(ncost < dist[nxt][nrecord]){
                q.push({nxt, nrecord, ncost});
                dist[nxt][nrecord] = ncost;
            }
            
        }
        
        
        
    }
    
    
    return;
}

int main(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> w[i][j];
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

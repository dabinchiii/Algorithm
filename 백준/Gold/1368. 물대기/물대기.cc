#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 300

using namespace std;

int N;
int g[MAX_N + 1][MAX_N + 1]; // 1~N번 노드가 논, 0번 노드가 물
int ans;

void solve(){
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(N + 1, false);
    int cnt = 0;
    
    pq.push({0, 0});
    
    while(!pq.empty()){
        int w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if(visited[v]) continue;
        
        visited[v] = true;
        ans += w;
        ++cnt;
        
        if(cnt == N + 1) break; // 0~N번 노드 => N + 1개
        
        for(int i=1; i<=N; i++){
            if(!visited[i]) pq.push({-g[v][i], i});
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> g[0][i];
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> g[i][j];
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

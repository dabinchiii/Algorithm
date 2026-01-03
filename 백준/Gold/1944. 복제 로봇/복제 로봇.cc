#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define MAX_N 50
#define MAX_NODE 251 // 로봇 출발지와 열쇠 위치 모두 노드로 생각

using namespace std;

struct loc{
    int r, c;
};

// 상하좌우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int N, M;
int board[MAX_N][MAX_N]; // 0: 빈칸, 1: 벽, 2: 노드(S or K)
map<int, int> nodeId;
vector<pair<int, int>> g[MAX_NODE];
int ans;

void findOthers(loc start, int id){ // bfs
    queue<pair<loc, int>> q; // {위치, 시작점부터의 거리}
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    
    q.push({start, 0});
    visited[start.r][start.c] = true;
    
    
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        
        for(int d=0; d<4; d++){
            int nr = curr.first.r + dr[d];
            int nc = curr.first.c + dc[d];
            int ndist = curr.second + 1;
            
            if(board[nr][nc] == 1) continue;
            if(visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            q.push({{nr, nc}, ndist});
            
            if(board[nr][nc] == 2){
                int key = (nr << 6) | nc;
                g[id].push_back({nodeId[key], ndist});
            }
        }
    }
    
    return;
}

int mst(){
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(M + 1, false);
    int cost = 0, cnt = 0;
    
    pq.push({0, 0});
    
    while(!pq.empty()){
        if(cnt == M + 1){
            return cost;
        }
        
        int currW = -pq.top().first;
        int currV = pq.top().second;
        pq.pop();
        
        if(visited[currV]) continue;
        
        visited[currV] = true;
        ++cnt;
        cost += currW;
        
        for(auto nxt : g[currV]){
            if(!visited[nxt.first]) pq.push({-nxt.second, nxt.first});
        }
    }
    
    if(cnt == M + 1) return cost;
    
    return -1;
}

void solve(){
    // 모든 간선 찾아서 양방향 그래프 만든다.
    // mst 구한다. 못 만들면 ans은 -1. 가능하면 총 비용이 ans
    
    for(auto curr : nodeId){
        int key = curr.first, id = curr.second;
        findOthers({key >> 6, key & ((1 << 6) - 1)}, id);
    }
    
    ans = mst();
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    int id = 0;
    string line;
    char ch;
    for(int i=0; i<N; i++){
        cin >> line;
        for(int j=0; j<N; j++){
            ch = line[j];
            if(ch == 'S' || ch == 'K'){
                ch = '2';
                int key = (i << 6) | j;
                nodeId[key] = id++;
            }
            
            board[i][j] = ch - '0';
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}


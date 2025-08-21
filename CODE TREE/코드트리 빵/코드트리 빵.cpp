#include <iostream>
#include <vector>
#include <queue>

#define INF 400
#define BASECAMP 1

using namespace std;

struct loc{
    int x, y;
};
struct person{
    int x, y;
};
struct conv{
    int x, y;
    bool done;
};
//struct basecamp{
//    int x, y;
//    bool done;
//};

// 상좌우하
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m;
int board[16][16];
vector<person> p(31);
vector<conv> conv(31);
bool isBlocked[16][16];
int ans;

void printStatus(){
    int res[16][16];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            res[i][j] = board[i][j];
            if(res[i][j] == BASECAMP) res[i][j] = -1;
            if(isBlocked[i][j]) res[i][j] = INF;
        }
    }
    
    for(int i=1; i<=m; i++){
        
        res[conv[i].x][conv[i].y] = -2;
        
        if(p[i].x != -1){
            res[p[i].x][p[i].y] = i;
        }
    }
    
    cout << "===== status =====\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%4d ", res[i][j]);
        }
        cout << endl;
    }
}
void bfs(int fromX, int fromY, vector<vector<int>>& dist){
    // {fromX, fromY}에서부터의 거리를 계산
    queue<pair<loc, int>> q;
    
    q.push({{fromX, fromY}, 0});
    dist[fromX][fromY] = 0;
    
    while(!q.empty()){
        loc curr = q.front().first;
        int currD = q.front().second;
        q.pop();
        
        for(int d=0; d<4; d++){
            loc nxt = {curr.x + dx[d], curr.y + dy[d]};
            
            if(nxt.x < 1 || nxt.x > n || nxt.y < 1 || nxt.y > n) continue;
            if(isBlocked[nxt.x][nxt.y]) continue;
            if(dist[nxt.x][nxt.y] != INF) continue; // dfs에서 이미 방문
            
            dist[nxt.x][nxt.y] = currD + 1;
            q.push({nxt, currD + 1});
        }
    }
    
    return;
}
void movePerson(int idx){
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    bfs(conv[idx].x, conv[idx].y, dist);
    
    int minD = INF;
    loc res;
    for(int d=0; d<4; d++){
        int nxtX = p[idx].x + dx[d];
        int nxtY = p[idx].y + dy[d];
        
        if(nxtX < 1 || nxtX > n || nxtY < 1 || nxtY > n) continue;
        if(isBlocked[nxtX][nxtY]) continue;
        
        if(dist[nxtX][nxtY] < minD){
            minD = dist[nxtX][nxtY];
            res = {nxtX, nxtY};
        }
    }
    
    p[idx] = {res.x, res.y};
    
    return;
}
bool isFinish(){
    for(int i=1; i<=m; i++){
        if(!conv[i].done) return false;
    }
    
    return true;
}
void solve(){
    int t = 1;
    
    while(true){
//        printStatus();
        
        // 1. "격자 내" 모두가 편의점 방향으로 1씩 이동
        for(int i=1; i<=m; i++){
            if(conv[i].done) continue; // 이미 도착
            if(p[i].x == -1) continue; // 격자 밖
            movePerson(i);
        }
        
        // 2. 편의점에 도착한 사람 체크
        for(int i=1; i<=m; i++){
            if(conv[i].done) continue; // 이미 도착
            
            if(p[i].x == conv[i].x && p[i].y == conv[i].y){
                conv[i].done= true;
                isBlocked[conv[i].x][conv[i].y] = true;
            }
            
        }
        
        // 모두 편의점에 도착했는지 (종료 조건) 체크
        if(isFinish()) break;
        
        
        // 3. t번 사람이 베이스캠프
        if(t <= m){
            vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
            bfs(conv[t].x, conv[t].y, dist);
            
            loc res;
            int minD = INF;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(board[i][j] == BASECAMP && dist[i][j] < minD){
                        minD = dist[i][j];
                        res = {i, j};
                    }
                }
            }
            
            p[t].x = res.x;
            p[t].y = res.y;
            isBlocked[res.x][res.y] = true;
            
        }
        
        t++;
    }
    
    ans = t;
    
    return;
}
int main(){
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i=1; i<=m; i++){
        cin >> conv[i].x >> conv[i].y;
        conv[i].done = false;
        
        p[i] = {-1, -1}; // 격자 밖
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}


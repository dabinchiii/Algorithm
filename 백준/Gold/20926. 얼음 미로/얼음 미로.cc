#include <iostream>
#include <vector>
#include <queue>

#define MAX_W 500
#define MAX_H 500

#define INF 2500000

#define ROCK -1
#define HOLE -2

using namespace std;

struct loc{
    int r, c;
};
struct gNode{
    loc nxt;
    int cost;
};

// 상하좌우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int W, H;
int board[MAX_H][MAX_W];
bool isInit[MAX_H][MAX_W];
vector<gNode> g[MAX_H][MAX_W];
loc s, e;
int ans;

bool isValid(int r, int c){
    return r >= 0 && r < H && c >= 0 && c < W;
}
void makeEdge(int sr, int sc){
    isInit[sr][sc] = true;
    
    for(int d=0; d<4; d++){
        int r = sr, c = sc, nr, nc;
        int cost = 0;
        while(true){
            nr = r + dr[d];
            nc = c + dc[d];
            
            if(!isValid(nr, nc) || board[nr][nc] == HOLE) break;
            if(board[nr][nc] == ROCK){
                if(r == sr && c == sc) break; // 처음 위치에서 이동하지 않았음
                g[sr][sc].push_back({{r, c}, cost});
                break;
            }
            if(nr == e.r && nc == e.c){
                g[sr][sc].push_back({{nr, nc}, cost});
                break;
            }
            
            r = nr;
            c = nc;
            cost += board[r][c];
        }
    }
    
    return;
}

void solve(){
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<int>> dist(H, vector<int>(W, INF));
    
    pq.push({0, {s.r, s.c}});
    dist[s.r][s.c] = 0;
    
    while(!pq.empty()){
        int currT = -pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        
        if(r == e.r && c == e.c){
            ans = currT;
            return;
        }
        
        if(dist[r][c] < currT) continue;
        
        if(!isInit[r][c]){
            makeEdge(r, c);
        }
        
        for(gNode nxt : g[r][c]){
            int nxtT = currT + nxt.cost;
            loc nxtV = nxt.nxt;
            if(dist[nxtV.r][nxtV.c] > nxtT){
                dist[nxtV.r][nxtV.c] = nxtT;
                pq.push({-nxtT, {nxtV.r, nxtV.c}});
            }
        }
    }
    
    ans = -1;
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> W >> H;
    
    string line;
    char ch;
    for(int i=0; i<H; i++){
        cin >> line;
        for(int j=0; j<W; j++){
            ch = line[j];
            if(ch == 'T'){
                board[i][j] = 0;
                s = {i, j};
            }
            else if(ch == 'R'){
                board[i][j] = ROCK;
            }
            else if(ch == 'H'){
                board[i][j] = HOLE;
            }
            else if(ch == 'E'){
                board[i][j] = 0;
                e = {i, j};
            }
            else{
                board[i][j] = ch - '0';
            }
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

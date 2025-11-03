#include <iostream>
#include <vector>
#include <queue>

#define MAX_N   100
#define MAX_K   100

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3

using namespace std;

struct loc{
    int r, c;
};

// 상하좌우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// 상하좌우 => 하상우좌
int opp[] = {DOWN, UP, RIGHT, LEFT};

int N, K, R;
bool isRoad[MAX_N + 1][MAX_N + 1][4];
loc cows[MAX_K];
int board[MAX_N + 1][MAX_N + 1];

void bfs(int sr, int sc, int id){
    queue<loc> q;
    q.push({sr, sc});
    board[sr][sc] = id;
    
    while(!q.empty()){
        loc curr = q.front();
        q.pop();
        
        for(int d=0; d<4; d++){
            if(isRoad[curr.r][curr.c][d]) continue;
            
            int nr = curr.r + dr[d];
            int nc = curr.c + dc[d];
            
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if(board[nr][nc] != 0) continue;
            
            board[nr][nc] = id;
            q.push({nr, nc});
        }
    }
    return;
}

void mark(){
    int currId = 0;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(board[i][j] != 0) continue; // 이미 방문
            bfs(i, j, ++currId);
        }
    }
    
    return;
}

int main(){
    cin >> N >> K >> R;
    
    int r1, c1, r2, c2;
    int vr, vc, v;
    for(int i=0; i<R; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        
        vr = r2 - r1;
        vc = c2 - c1;
        
        if(vr < 0 && vc == 0) v = UP;
        else if(vr > 0 && vc == 0) v = DOWN;
        else if(vr == 0 && vc < 0) v = LEFT;
        else if(vr == 0 && vc > 0) v = RIGHT;
        else v = -1;
        
        isRoad[r1][c1][v] = true;
        isRoad[r2][c2][opp[v]] = true;
    }
    
    for(int i=0; i<K; i++){
        cin >> cows[i].r >> cows[i].c;
    }
    
    mark(); // flood fill로 땅 덩어리 구분하여 id 부여
    
    int ans = 0;
    for(int i=0; i<K; i++){
        for(int j=i + 1; j<K; j++){
            if(board[cows[i].r][cows[i].c] != board[cows[j].r][cows[j].c]) ++ans;
        }
    }
    
    cout << ans;
    
    return 0;
}

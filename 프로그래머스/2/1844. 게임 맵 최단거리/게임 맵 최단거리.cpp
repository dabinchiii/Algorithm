#include <vector>
#include <queue>

#define MAX_N 100
#define MAX_M 100

#define MASK_R (0b11111110000000)
#define MASK_C (0b1111111)
#define SHIFT_CNT 14
#define SHIFT_R 7

using namespace std;

int N, M;
queue<int> q;
bool visited[MAX_N][MAX_M];

// 상하좌우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool check(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < M;
}

int solution(vector<vector<int>> maps) {
    N = maps.size();
    M = maps[0].size();
    
    q.push({0});
    visited[0][0] = true;
    
    while(!q.empty()){
        int curr = q.front(); q.pop();
        int r = (curr & MASK_R) >> SHIFT_R;
        int c = curr & MASK_C;
        int cnt = curr >> SHIFT_CNT;
        
        if(r == N - 1 && c == M - 1){
            return cnt + 1;
        }
        
        for(int d=0; d<4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            if(!check(nr, nc)) continue;
            if(maps[nr][nc] == 0) continue;
            if(visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            
            int val = (cnt + 1) << SHIFT_CNT;
            val |= nr << SHIFT_R;
            val |= nc;
            q.push(val);
        }
    }
    
    return -1;    
}
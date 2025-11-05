#include <iostream>

#define MAX_N 20
#define MAX_M 400

using namespace std;

struct sharkInfo{
    int r, c;
    int dir;
    int prior[4][4];
    bool isDead;
};
struct smellNode{
    int id, end;
};

// 상하좌우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int N, M, K;
int board[MAX_N][MAX_N];
smellNode smell[MAX_N][MAX_N];
sharkInfo shark[MAX_M + 1];
int cntLeft;
int ans;

bool check(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < N;
}

void moveAll(int t){
    int newBoard[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            newBoard[i][j] = 0;
        }
    }
    
    for(int i=M; i>=1; i--){
        if(shark[i].isDead) continue;
        
        int nd = -1;
        int *prior = shark[i].prior[shark[i].dir]; // 현재 상어의 방향 우선순위
        for(int j=0; j<4; j++){
            int d = prior[j];
            int nr = shark[i].r + dr[d];
            int nc = shark[i].c + dc[d];
            
            if(!check(nr, nc)) continue;
            
            if(smell[nr][nc].end < t){ // 냄새 X
                nd = d;
                break;
            }
        }
        if(nd == -1){
            for(int j=0; j<4; j++){
                int d = prior[j];
                int nr = shark[i].r + dr[d];
                int nc = shark[i].c + dc[d];
                
                if(!check(nr, nc)) continue;
                
                if(smell[nr][nc].id == i){
                    nd = d;
                    break;
                }
            }
        }
        
        int r = shark[i].r + dr[nd];
        int c = shark[i].c + dc[nd];
        
        shark[i].r = r;
        shark[i].c = c;
        shark[i].dir = nd;
        
        if(newBoard[r][c] != 0){
            shark[newBoard[r][c]].isDead = true;
            --cntLeft;
        }
        
        newBoard[r][c] = i;
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            board[i][j] = newBoard[i][j];
        }
    }
    
    return;
}
void spread(int t){
    for(int i=1; i<=M; i++){
        if(shark[i].isDead) continue;
        smell[shark[i].r][shark[i].c] = {i, t + K};
    }
    
    return;
}
void print(int t){
    printf("=== t=%d ===\n", t);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", board[i][j]);
        }
        cout << endl;
    }
}
void solve(){
    ans = -1;
    cntLeft = M;
    
    for(int i=1; i<=M; i++){ // 모든 상어가 자신의 위치에 자신의 냄새를 뿌린다.
        smell[shark[i].r][shark[i].c] = {i, K};
    }
    
    for(int t=1; t<=1000; t++){
        moveAll(t);
        
        if(cntLeft == 1){
            ans = t;
            break;
        }
        
        spread(t);
        
        //print(t);
    }
    
    return;
}

int main(){
    cin >> N >> M >> K;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            shark[board[i][j]].r = i;
            shark[board[i][j]].c = j;
        }
    }
    
    for(int i=1; i<=M; i++){
        cin >> shark[i].dir;
        --shark[i].dir;
        shark[i].isDead = false;
    }
    
    int dir;
    for(int i=1; i<=M; i++){
        for(int d=0; d<4; d++){
            for(int j=0; j<4; j++){
                cin >> dir;
                shark[i].prior[d][j] = dir - 1;
            }
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

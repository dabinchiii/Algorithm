#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct loc{
    int r, c;
};

int N, M, D;
int origin[15][15], board[15][15];
loc bow[3];
int ans;

// 궁수 3명을 성 칸 중에 배치
// 각 턴마다 궁수는 하나의 적을 공격
// 거리가 D 이하인 적 중 가장 가깝고, 가장 왼쪽에 있는 적 공격
// 궁수는 동시에 공격하므로, 같은 적이 동시에 여러 궁수에게 공격받을 수 있음
// 궁수 공격 이후, 공격당한 적은 제외되고, 이후 적들이 이동
// 적 이동: 한 칸 아래로 이동, 성에 도착하면 제외됨
// 게임 종료: 모든 적이 제외됨
// ans: "궁수 공격으로" (성 도착이 아니라) 제거할 수 있는 적 최대 수

int getDistance(loc a, loc b){
    return abs(a.r - b.r) + abs(a.c - b.c);
}

bool isEnd(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j]) return false;
        }
    }
    return true;
}

loc selectTarget(loc curr){
    // 거리가 D 이하인 적 중 가장 가깝고, 여러 개라면 가장 왼쪽에 있는 적
    loc target = {-1, -1};
    int minDist = 4000, minCol = -1;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] == 0) continue;
            
            int dist = getDistance(curr, {i, j});
            if(dist > D) continue;
            
            if(dist < minDist){
                minDist = dist;
                minCol = j;
                target = {i, j};
            }
            else if(dist == minDist){
                if(j < minCol){
                    minDist = dist;
                    minCol = j;
                    target = {i, j};
                }
            }
        }
    }
    return target;
}

void play(){
    loc target[3];
    int cnt = 0;
    
    while(!isEnd()){
        // 궁수 별 공격할 적 선택
        for(int i=0; i<3; i++){
            target[i] = selectTarget(bow[i]);
        }
        
        // 적 제거 및 카운팅
        for(int i=0; i<3; i++){
            if(target[i].r == -1) continue;
            if(board[target[i].r][target[i].c] == 0) continue; // 앞 궁수가 제거함
            board[target[i].r][target[i].c] = 0;
            ++cnt;
        }
        
        // 적 이동
        for(int i=0; i<M; i++) board[N-1][i] = 0;
        for(int i=N-2; i>=0; i--){
            for(int j=0; j<M; j++){
                if(board[i][j] == 0) continue;
                board[i + 1][j] = 1;
                board[i][j] = 0;
            }
        }
        
    }
    
    ans = max(ans, cnt);
    
    return;
}
void initBoard(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            board[i][j] = origin[i][j];
        }
    }
}
void solve(){
    bow[0].r = bow[1].r = bow[2].r = N;
    
    for(int i=0; i<M; i++){
        for(int j=i+1; j<M; j++){
            for(int k=j+1; k<M; k++){
                initBoard();
                
                bow[0].c = i;
                bow[1].c = j;
                bow[2].c = k;
                
                play();
            }
        }
    }
    
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> D;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> origin[i][j];
        }
    }
    
    solve();
    cout << ans;

    return 0;
}

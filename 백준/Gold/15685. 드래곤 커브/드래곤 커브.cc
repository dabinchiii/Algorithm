#include <iostream>
#include <vector>
#include <queue>

#define UP 1
#define DOWN 3
#define LEFT 2
#define RIGHT 0

using namespace std;

// 우상좌하
int dr[] = { 0, -1, 0, 1 };
int dc[] = { 1, 0, -1, 0 };

// 반시계: 우상좌하 => 상좌하우
int ccw[] = { UP, LEFT, DOWN, RIGHT };

bool board[101][101];

void mark(int x, int y, int dir, int g){
    vector<int> path;
    path.push_back(dir);
    
    // path 생성
    for(int i=0; i<g; i++){
        for(int j=(int)path.size() - 1; j>=0; j--){
            path.push_back(ccw[path[j]]);
        }
    }
    /*
    for(int curr : path){
        if(curr == 0) cout << "> ";
        else if(curr == 1) cout << "^ ";
        else if(curr == 2) cout << "< ";
        else cout << "v ";
    }
    cout << endl;
     */
    
    // path 그리기
    int r = y, c = x;
    board[r][c] = true;
    for(int d : path){
        r += dr[d];
        c += dc[d];
        
        board[r][c] = true;
    }
    
    return;
}

int main(){
    
    int N;
    cin >> N;
    
    int x, y, d, g;
    for(int i=0; i<N; i++){
        cin >> x >> y >> d >> g;
        mark(x, y, d, g);
    }
    
    int ans = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ++ans;
        }
    }
    
    cout << ans;
    
    return 0;
}

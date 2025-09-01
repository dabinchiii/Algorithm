#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct loc {
    int r, c;
};

int N, M;
int board[8][8];
vector<loc> cctvs;
int ans;

// 상하좌우
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

// 시계방향 상하좌우 -> 우좌상하
int cw[] = {3, 2, 0, 1};

// 반시계방향 상하좌우 -> 좌우하상
int ccw[] = {2, 3, 1, 0};

// 반대방향 상하좌우 -> 하상우좌
int opp[] = {1, 0, 3, 2};

bool check(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

void print() {
    cout << "=======================\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == -1) cout << '#';
            else cout << board[i][j];
            cout << ' ';
        }
        cout << endl;
    }
}
void mark(int r, int c, int d) { // (r, c)에서 d 방향으로
    int nr = r, nc = c;
    while (true) {
        nr += dr[d];
        nc += dc[d];

        if (!check(nr, nc)) break;
        if (board[nr][nc] == 6) break;
        if (board[nr][nc] > 0) continue; // cctv인 경우 통과

        board[nr][nc] = -1; // 시야 표시
    }
    return;
}

int cntBlind() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) cnt++;
        }
    }

    return cnt;
}
void dfs(int cnt) {
    if (cnt == cctvs.size()) {
        ans = min(ans, cntBlind());
        // print();
 
        return;
    }

    loc curr = cctvs[cnt];
    int k = board[curr.r][curr.c]; // cctv 종류

    int tmp[8][8];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tmp[i][j] = board[i][j];
        }
    }
    
    for(int d=0; d<4; d++){
        if (k == 1) {
            mark(curr.r, curr.c, d);
        }
        else if (k == 2) {
            mark(curr.r, curr.c, d);
            mark(curr.r, curr.c, opp[d]);
        }
        else if (k == 3) {
            mark(curr.r, curr.c, d);
            mark(curr.r, curr.c, ccw[d]);
        }
        else if (k == 4) {
            mark(curr.r, curr.c, d);
            mark(curr.r, curr.c, ccw[d]);
            mark(curr.r, curr.c, opp[d]);
        }
        else if (k == 5) {
            if(d > 0) continue;
            mark(curr.r, curr.c, d);
            mark(curr.r, curr.c, cw[d]);
            mark(curr.r, curr.c, ccw[d]);
            mark(curr.r, curr.c, opp[d]);
        }
        
        dfs(cnt + 1);
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                board[i][j] = tmp[i][j];
            }
        }
    }
    
    return;
}
void solve() {
    ans = 64;
    dfs(0);
    return;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5) {
                cctvs.push_back({ i, j });
            }
        }
    }

    solve();

    cout << ans;

    return 0;
}

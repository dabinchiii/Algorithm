#include <bits/stdc++.h>
#define BLANK -1
#define BOMB_OLD 1
#define BOMB_NEW 2

using namespace std;

int r, c, n;
int board[201][201];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void passTime(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j] == BLANK) continue;
            board[i][j]--;
        }
    }

    return;
}

void installBomb(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j] == BLANK) board[i][j] = BOMB_NEW;
        }
    }

    return;
}

void explodeAll(){
    int nxtBoard[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            nxtBoard[i][j] = board[i][j];
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j] != 0) continue;

            nxtBoard[i][j] = BLANK;

            int nxtX, nxtY;
            for(int k=0; k<4; k++){
                nxtX = i + dx[k];
                nxtY = j + dy[k];

                if(nxtX < 0 || nxtX >= r) continue;
                if(nxtY < 0 || nxtY >= c) continue;

                nxtBoard[nxtX][nxtY] = BLANK;
            }
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            board[i][j] = nxtBoard[i][j];
        }
    }

    return;
}

void solve(){
    passTime();
    for(int t=1; t<n; t++){
        if(t % 2 == 1){
            passTime();
            installBomb();
        }
        else{
            explodeAll();
            passTime();
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> n;

    string line;
    for(int i=0; i<r; i++){
        cin >> line;
        for(int j=0; j<c; j++){
            board[i][j] = (line[j] == '.' ? BLANK : BOMB_NEW);
        }
    }

    solve();

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << (board[i][j] == BLANK ? '.' : 'O');
        }
        cout << '\n';
    }

    return 0;
}

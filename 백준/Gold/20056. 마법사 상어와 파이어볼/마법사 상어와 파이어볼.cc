#include <bits/stdc++.h>

using namespace std;

typedef struct fireball{
    int m, s, d;
}fireball;

int N, M, K;
queue<fireball> board[50][50];
int ans;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void moveAll(){
    queue<fireball> newBoard[50][50];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            while(!board[i][j].empty()){
                fireball f = board[i][j].front();
                board[i][j].pop();

                int nxtX = (i + dx[f.d] * f.s) % N;
                nxtX = (nxtX + N) % N;
                int nxtY = (j + dy[f.d] * f.s) % N;
                nxtY = (nxtY + N) % N;
                //cout << nxtX << ' ' << nxtY << endl;
                newBoard[nxtX][nxtY].push(f);
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            board[i][j] = newBoard[i][j];
        }
    }

    return;
}

void updateAll(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board[i][j].size() < 2) continue;

            int cnt = board[i][j].size();
            int sumM = 0, sumS = 0;
            bool isAllOdd = true, isAllEven = true;
            while(!board[i][j].empty()){
                fireball f = board[i][j].front();
                board[i][j].pop();

                sumM += f.m;
                sumS += f.s;

                if(f.d % 2) isAllOdd = false;
                else isAllEven = false;
            }

            int newM = sumM / 5;
            int newS = sumS / cnt;
            int newD = (isAllOdd || isAllEven ? 0 : 1);

            if(newM == 0) continue;

            for(int k=0; k<4; k++){
                board[i][j].push({newM, newS, newD});
                newD += 2;
            }
        }
    }

    return;
}

void solve(){
    for(int i=0; i<K; i++){
        moveAll();
        updateAll();
    }

    ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            while(!board[i][j].empty()){
                ans += board[i][j].front().m;
                board[i][j].pop();
            }
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    int r, c;
    fireball f;
    for(int i=0; i<M; i++){
        cin >> r >> c >> f.m >> f.s >> f.d;
        r--;
        c--;
        board[r][c].push(f);
    }

    solve();

    cout << ans;

    return 0;
}

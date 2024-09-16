#include <bits/stdc++.h>

#define BLANK '.'
#define WATER '*'
#define STONE 'X'
#define BV 'D'
#define HH 'S'

using namespace std;

int r, c;
char board[50][50];
bool visited[50][50];
int ans, t;

queue<pair<int, int>> q_water, q_hh;
pair<int, int> bv;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void spreadWater(){
    int cnt = q_water.size();

    for(int i=0; i<cnt; i++){
        int currX = q_water.front().first;
        int currY = q_water.front().second;
        q_water.pop();

        for(int j=0; j<4; j++){
            int nxtX = currX + dx[j];
            int nxtY = currY + dy[j];

            if(nxtX < 0 || nxtX >= r) continue;
            if(nxtY < 0 || nxtY >= c) continue;
            if(board[nxtX][nxtY] != BLANK) continue;

            q_water.push({nxtX, nxtY});
            board[nxtX][nxtY] = WATER;
        }
    }

    return;
}

void moveHH(){
    int cnt = q_hh.size();

    for(int i=0; i<cnt; i++){
        int currX = q_hh.front().first;
        int currY = q_hh.front().second;
        q_hh.pop();

        if(board[currX][currY] == BV){
            ans = t;
            while(!q_hh.empty()){
                q_hh.pop();
            }

            return;
        }

        for(int j=0; j<4; j++){
            int nxtX = currX + dx[j];
            int nxtY = currY + dy[j];

            if(nxtX < 0 || nxtX >= r) continue;
            if(nxtY < 0 || nxtY >= c) continue;
            if(board[nxtX][nxtY] == WATER) continue;
            if(board[nxtX][nxtY] == STONE) continue;
            if(visited[nxtX][nxtY]) continue;

            q_hh.push({nxtX, nxtY});
            visited[nxtX][nxtY] = true;
        }

    }

    return;
}

void solve(){
    ans = -1;
    t = 0;
    while(!q_hh.empty()){
        spreadWater();
        moveHH();
        t++;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    string str;
    for(int i=0; i<r; i++){
        cin >> str;
        for(int j=0; j<c; j++){
            board[i][j] = str[j];

            if(board[i][j] == WATER) q_water.push({i, j});
            else if(board[i][j] == HH){
                q_hh.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    solve();

    if(ans == -1) cout << "KAKTUS";
    else cout << ans;

    return 0;
}

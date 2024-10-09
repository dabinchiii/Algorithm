#include <bits/stdc++.h>

using namespace std;

typedef struct shark{
    int s, d, z;
}shark;

int r, c, m;
shark board[101][101];
bool isShark[101][101];
int ans;

// 1:위, 2:아래, 3:오른쪽, 4:왼쪽
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

int opp[] = {0, 2, 1, 4, 3};

void catchAShark(int curr){
    for(int i=0; i<r; i++){
        if(!isShark[i][curr]) continue;

        ans += board[i][curr].z;
        isShark[i][curr] = false;
        break;
    }

    return;
}

void moveAllSharks(){
    queue<pair<pair<int, int>, shark>> q;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!isShark[i][j]) continue;

            shark sh = board[i][j];
            int dis = sh.s;

            int x = i, y = j;
            while(dis){
                x += dx[sh.d];
                y += dy[sh.d];

                if(x < 0 || x >= r || y < 0 || y >= c){
                    sh.d = opp[sh.d];
                    x += dx[sh.d] * 2;
                    y += dy[sh.d] * 2;
                }

                dis--;
            }

            q.push({{x, y}, sh});
            isShark[i][j] = false;
        }
    }

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        shark sh = q.front().second;
        q.pop();

        if(isShark[x][y] && board[x][y].z > sh.z) continue;

        isShark[x][y] = true;
        board[x][y] = sh;
    }

    return;
}

void solve(){
    for(int i=0; i<c; i++){
        catchAShark(i);
        moveAllSharks();
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> m;

    int x, y;
    shark sh;
    for(int i=0; i<m; i++){
        cin >> x >> y >> sh.s >> sh.d >> sh.z;
        x--; y--;

        if(sh.d <= 2) sh.s %= 2 * (r - 1);
        else sh.s %= 2 * (c - 1);

        board[x][y] = sh;
        isShark[x][y] = true;
    }

    solve();

    cout << ans;

    return 0;
}

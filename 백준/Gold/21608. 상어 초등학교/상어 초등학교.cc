#include <bits/stdc++.h>

using namespace std;

int n;
bool like[401][401];
int board[20][20];
vector<int> s;
int ans;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int satisfaction[] = {0, 1, 10, 100, 1000};

void setSeat(int currSt){
    int optSeatLike = -1, optSeatBlank = -1;
    int optSeatX, optSeatY;

    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            if(board[x][y] != 0) continue;

            int cntLike = 0, cntBlank = 0;

            for(int i=0; i<4; i++){
                int nxtX = x + dx[i];
                int nxtY = y + dy[i];

                if(nxtX < 0 || nxtX >= n) continue;
                if(nxtY < 0 || nxtY >= n) continue;

                if(board[nxtX][nxtY] == 0) cntBlank++;
                if(like[currSt][board[nxtX][nxtY]]) cntLike++;
            }

            if(cntLike > optSeatLike || (cntLike == optSeatLike && cntBlank > optSeatBlank)){
                optSeatLike = cntLike;
                optSeatBlank = cntBlank;

                optSeatX = x;
                optSeatY = y;
            }

        }
    }

    board[optSeatX][optSeatY] = currSt;

    return;
}

int getScore(int x, int y){
    int cnt = 0;

    for(int i=0; i<4; i++){
        int nxtX = x + dx[i];
        int nxtY = y + dy[i];

        if(nxtX < 0 || nxtX >= n) continue;
        if(nxtY < 0 || nxtY >= n) continue;

        if(like[board[x][y]][board[nxtX][nxtY]]) cnt++;
    }

    return satisfaction[cnt];
}

void survey(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans += getScore(i, j);
        }
    }

    return;
}

void solve(){
    for(int currSt : s){
        setSeat(currSt);
    }

    survey();

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int currSt, likeSt;
    for(int i=0; i<n * n; i++){
        cin >> currSt;
        s.push_back(currSt);

        for(int j=0; j<4; j++){
            cin >> likeSt;
            like[currSt][likeSt] = true;
        }
    }

    solve();

    cout << ans;

    return 0;
}

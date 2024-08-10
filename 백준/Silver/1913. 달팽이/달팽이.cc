#include <bits/stdc++.h>
#define MAX_N 999

using namespace std;

int n, q;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int currX, currY, currD, currNum;
int ansX, ansY;

// 남->동->북->서
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void setD(){
    int nxtX = currX + dx[currD];
    int nxtY = currY + dy[currD];

    bool blocked = false;

    if(nxtX < 0 || nxtX >= n) blocked = true;
    if(nxtY < 0 || nxtY >= n) blocked = true;
    if(visited[nxtX][nxtY]) blocked = true;

    if(blocked){
        currD = (currD + 1) % 4;
    }

    return;
}

void solve(){
    currX = 0;
    currY = 0;
    currD = 0;

    currNum = n * n;

    while(currNum){
        if(currNum == q){
            ansX = currX + 1;
            ansY = currY + 1;
        }

        board[currX][currY] = currNum;
        visited[currX][currY] = true;
        currNum--;

        setD();
        currX += dx[currD];
        currY += dy[currD];
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    solve();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << ansX << ' ' << ansY;

    return 0;
}

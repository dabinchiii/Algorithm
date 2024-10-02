#include <bits/stdc++.h>

using namespace std;

int n, k;
int x, y, s;
int ans;
int board[200][200];
priority_queue<pair<int, pair<int, int>>> virus;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void multiply(){
    vector<pair<int, pair<int, int>>> v;

    while(!virus.empty()){
        int currV = -virus.top().first;
        int currX = virus.top().second.first;
        int currY = virus.top().second.second;
        virus.pop();

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= n) continue;
            if(board[nxtX][nxtY] != 0) continue;

            board[nxtX][nxtY] = currV;
            v.push_back({-currV, {nxtX, nxtY}});
        }


    }

    for(pair<int, pair<int, int>> curr : v){
        virus.push(curr);
    }

    return;
}

void solve(){
    for(int t=0; t<s; t++){
        multiply();
    }

    ans = board[x][y];

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            virus.push({-board[i][j], {i, j}});
        }
    }

    cin >> s >> x >> y;
    x--; y--;

    solve();

    cout << ans;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, m;
bool isCheese[101][101];
int cntCheese;
int ans;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void melt(){
    vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX > n) continue;
            if(nxtY < 0 || nxtY > m) continue;
            if(isCheese[nxtX][nxtY]) continue;
            if(visited[nxtX][nxtY]) continue;

            for(int j=0; j<4; j++){
                int x = nxtX + dx[j];
                int y = nxtY + dy[j];

                if(x < 0 || x > n) continue;
                if(y < 0 || y > m) continue;
                if(!isCheese[x][y]) continue;
                cnt[x][y]++;
            }

            visited[nxtX][nxtY] = true;
            q.push({nxtX, nxtY});
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(cnt[i][j] < 2) continue;

            isCheese[i][j] = false;
            cntCheese--;
        }
    }

    return;
}

void solve(){
    int t = 0;
    while(cntCheese > 0){
        melt();
        t++;
    }

    ans = t;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> isCheese[i][j];
            if(isCheese[i][j]) cntCheese++;
        }
    }

    solve();

    cout << ans;

    return 0;
}

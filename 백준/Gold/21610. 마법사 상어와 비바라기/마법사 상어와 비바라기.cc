#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[50][50];
pair<int, int> comm[100];
int ans;

queue<pair<int, int>> cloud;

int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

void waterCopyBugMagic(queue<pair<int, int>> q){
    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        int cnt = 0;
        for(int i=1; i<=4; i++){
            int nxtX = currX + dx[2 * i];
            int nxtY = currY + dy[2 * i];

            // 경계를 넘어가는 칸 제외
            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= n) continue;

            // 물 없음
            if(board[nxtX][nxtY] == 0) continue;

            cnt++;
        }
        board[currX][currY] += cnt;
    }

    return;
}

void moveCloud(int d, int s){
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    queue<pair<int, int>> q; // 물이 증가한 칸

    while(!cloud.empty()){
        int currX = cloud.front().first;
        int currY = cloud.front().second;
        cloud.pop();

        int nxtX = (currX + dx[d] * s) % n;
        nxtX = (nxtX + n) % n;
        int nxtY = (currY + dy[d] * s) % n;
        nxtY = (nxtY + n) % n;

        visited[nxtX][nxtY] = true;
        board[nxtX][nxtY]++;
        q.push({nxtX, nxtY});
    }

    waterCopyBugMagic(q);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] < 2 || visited[i][j]) continue;

            cloud.push({i, j});
            board[i][j] -= 2;
        }
    }

    return;
}

void solve(){
    cloud.push({n - 1, 0});
    cloud.push({n - 1, 1});
    cloud.push({n - 2, 0});
    cloud.push({n - 2, 1});

    for(int i=0; i<m; i++){
        moveCloud(comm[i].first, comm[i].second);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans += board[i][j];
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<m; i++){
        cin >> comm[i].first >> comm[i].second;
    }

    solve();

    cout << ans;

    return 0;
}

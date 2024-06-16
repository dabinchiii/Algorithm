#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_M 1000

using namespace std;

int n, m;
int board[MAX_N][MAX_M];
int ans[MAX_N][MAX_M];
map<int, int> area;
int areaNum;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y){
    priority_queue<pair<int, int>> q;
    q.push({x, y});
    board[x][y] = ++areaNum;
    area[areaNum]++;

    while(!q.empty()){
        int currX = q.top().first;
        int currY = q.top().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= m) continue;
            if(board[nxtX][nxtY] != 0) continue;

            board[nxtX][nxtY] = areaNum;
            area[areaNum]++;

            q.push({nxtX, nxtY});
        }
    }

    return;
}

void checkArea(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] != 0) continue;
            bfs(i, j);
        }
    }

    return;
}

void solve(){
    checkArea();

    int nxtX, nxtY;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] != -1) continue;

            ans[i][j] = 1;
            set<int> s;
            for(int k=0; k<4; k++){
                nxtX = i + dx[k];
                nxtY = j + dy[k];

                if(nxtX < 0 || nxtX >= n) continue;
                if(nxtY < 0 || nxtY >= m) continue;
                if(s.find(board[nxtX][nxtY]) != s.end()) continue;

                s.insert(board[nxtX][nxtY]);
                ans[i][j] += area[board[nxtX][nxtY]];
                //ans[i][j] %= 10;
            }
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    string str;
    int num;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            num = str[j] - '0';
            board[i][j] = num == 1 ? -1 : 0;
        }
    }

    solve();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << ans[i][j] % 10;
        }
        cout << '\n';
    }

    return 0;
}

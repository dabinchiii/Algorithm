#include <bits/stdc++.h>
#define MAX_N 50
using namespace std;

int n, l, r;
int a[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int cnt = 9999;
int Answer;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void init(){
    cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
}

void bfs(int x, int y){
    queue<pair<int, int>> q, u;
    q.push({x, y});
    u.push({x, y});

    int sum = a[x][y];
    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= n) continue;

            if(visited[nxtX][nxtY]) continue;

            int diff = abs(a[nxtX][nxtY] - a[currX][currY]);
            if(diff < l || diff > r) continue;

            // nxt는 연합에 속함
            sum += a[nxtX][nxtY];
            visited[nxtX][nxtY] = true;
            u.push({nxtX, nxtY});
            q.push({nxtX, nxtY});

            cnt++;
        }
    }

    int avg = sum / (int)u.size();
    while(!u.empty()){
        int currX = u.front().first;
        int currY = u.front().second;
        u.pop();

        a[currX][currY] = avg;
    }
}

void round(){
    init();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                bfs(i, j);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    while(cnt > 0){
        round();
        Answer++;
    };
    Answer -= 1;

    cout << Answer;

    return 0;
}

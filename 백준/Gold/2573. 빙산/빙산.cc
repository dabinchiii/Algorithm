#include <bits/stdc++.h>
#define MAX 300

using namespace std;

int n, m;
vector<vector<int>> arr(MAX, vector<int>(MAX));
vector<vector<bool>> visited(MAX, vector<bool>(MAX));

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = false;
        }
    }
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= m) continue;
            if(arr[nxtX][nxtY] == 0) continue;
            if(visited[nxtX][nxtY]) continue;

            visited[nxtX][nxtY] = true;
            q.push({nxtX, nxtY});
        }
    }
}

void melt(){
    vector<vector<int>> nxt(arr);

    for(int i=1; i<n-1; i++){
        for(int j=1; j<m-1; j++){
            if(arr[i][j] == 0) continue;

            int sum = 0;
            for(int k=0; k<4; k++){
                if(arr[i + dx[k]][j + dy[k]] == 0) sum++;
            }
            nxt[i][j] = max(0, nxt[i][j] - sum);
        }
    }
    arr = nxt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    bool isSeperated = false;
    int Answer = 0;

    while(1){
        int cnt = 0;
        init();

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(arr[i][j] > 0 && !visited[i][j]){
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        if(cnt >= 2){
            isSeperated = true;
            break;
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                sum += arr[i][j];
        }
        if(sum == 0){
            break;
        }

        melt();
        Answer++;
    }

    cout << (isSeperated ? Answer : 0);

    return 0;
}

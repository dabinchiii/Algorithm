#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int n, m;
vector<vector<int>> arr(MAX + 2, vector<int>(MAX + 2, 0));
vector<vector<bool>> visited(MAX + 2, vector<bool>(MAX + 2));
int AnswerT, AnswerCnt, cnt;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void init(){
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            visited[i][j] = false;
        }
    }
    cnt = 0;
}

void bfs(){
    vector<vector<int>> nxt(arr);

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX > n + 1) continue;
            if(nxtY < 0 || nxtY > m + 1) continue;

            if(visited[nxtX][nxtY]) continue;

            visited[nxtX][nxtY] = true;

            if(arr[nxtX][nxtY] == 1){
                nxt[nxtX][nxtY] = 0;
                cnt++;
            }
            else if(arr[nxtX][nxtY] == 0){
                q.push({nxtX, nxtY});
            }
        }
    }

    arr = nxt;
    if(cnt != 0) AnswerCnt = cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }

    do{
        init();
        bfs();
        AnswerT++;
    }while(cnt > 0);

    AnswerT--;
    cout << AnswerT << '\n' << AnswerCnt;

    return 0;
}

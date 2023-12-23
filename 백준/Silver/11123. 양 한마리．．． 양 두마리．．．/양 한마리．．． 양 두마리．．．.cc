#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int h, w;
vector<vector<char>> arr(MAX, vector<char>(MAX));
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void init(){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
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

            if(nxtX < 0 || nxtX >= h) continue;
            if(nxtY < 0 || nxtY >= w) continue;
            if(arr[nxtX][nxtY] != '#') continue;
            if(visited[nxtX][nxtY]) continue;

            visited[nxtX][nxtY] = true;
            q.push({nxtX, nxtY});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        init();

        cin >> h >> w;

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> arr[i][j];
            }
        }

        int cnt = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(arr[i][j] == '#' && !visited[i][j]){
                    cnt++;
                    bfs(i, j);
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}

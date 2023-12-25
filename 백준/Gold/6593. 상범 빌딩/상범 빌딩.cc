#include <bits/stdc++.h>
#define MAX_L 30
#define MAX_R 30
#define MAX_C 30

using namespace std;

struct pos{
    int x, y, z;
};

int l, r, c;
char arr[MAX_L][MAX_R][MAX_C];
bool visited[MAX_L][MAX_R][MAX_C];
struct pos s;
bool findExit;
int Answer;

// 동, 서, 남, 북, 상, 하
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void init(){
    findExit = false;
    Answer = 0;

    for(int i=0; i<l; i++){
        for(int j=0; j<r; j++){
            for(int k=0; k<c; k++){
                visited[i][j][k] = false;
            }
        }
    }
}
void bfs(struct pos start){
    queue<pair<struct pos, int>> q;
    q.push({start, 0});
    visited[start.z][start.x][start.y] = true;

    while(!q.empty()){
        int currX = q.front().first.x;
        int currY = q.front().first.y;
        int currZ = q.front().first.z;
        int currDis = q.front().second;

        q.pop();

        if(arr[currZ][currX][currY] == 'E'){
            findExit = true;
            Answer = currDis;
            break;
        }

        for(int i=0; i<6; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];
            int nxtZ = currZ + dz[i];

            if(nxtX < 0 || nxtX >= r) continue;
            if(nxtY < 0 || nxtY >= c) continue;
            if(nxtZ < 0 || nxtZ >= l) continue;
            if(visited[nxtZ][nxtX][nxtY]) continue;
            if(arr[nxtZ][nxtX][nxtY] == '#') continue;

            visited[nxtZ][nxtX][nxtY] = true;
            q.push({{nxtX, nxtY, nxtZ}, currDis + 1});
        }
    }
}

void solve(){
    for(int i=0; i<l; i++){
        for(int j=0; j<r; j++){
            for(int k=0; k<c; k++){
                cin >> arr[i][j][k];

                if(arr[i][j][k] == 'S') s = {j, k, i};
            }
        }
    }

    bfs(s);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        cin >> l >> r >> c;
        if(l + r + c == 0) break;

        init();
        solve();

        if(findExit) cout << "Escaped in " << Answer << " minute(s).\n";
        else cout << "Trapped!\n";
    }

    return 0;
}

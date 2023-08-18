#include <bits/stdc++.h>
#define MAX 250
using namespace std;

int r, c;
char area[MAX][MAX];
bool visited[MAX][MAX];
int currK, currV;
int AnsK, AnsV;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    if(area[y][x] == 'v') currV++;
    else if(area[y][x] == 'k') currK++;

    for(int i=0; i<4; i++){
        int nxtY = y + dy[i];
        int nxtX = x + dx[i];

        if(nxtY < 0 || nxtY >= r) continue;
        if(nxtX < 0 || nxtX >= c) continue;
        if(visited[nxtY][nxtX] || area[nxtY][nxtX] == '#') continue;

        visited[nxtY][nxtX] = true;
        dfs(nxtY, nxtX);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> area[i][j];
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!visited[i][j] && area[i][j] != '#'){
                currK = currV = 0;
                visited[i][j] = true;
                dfs(i, j);

                if(currK > currV) currV = 0; // 늑대 잡아먹힘
                else currK = 0; // 양 잡아먹힘

                AnsK += currK;
                AnsV += currV;
            }
        }
    }

    cout << AnsK << ' ' << AnsV; // 양, 늑대

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int r, c, k;
bool MAP[5][5], visited[5][5];
int currDist;
int Answer;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    if(y == 0 && x == c-1){
        if(currDist == k) Answer++;
        return;
    }

    for(int i=0; i<4; i++){
        int nxtY = y + dy[i];
        int nxtX = x + dx[i];

        if(nxtY < 0 || nxtY >= r) continue;
        if(nxtX < 0 || nxtX >= c) continue;
        if(visited[nxtY][nxtX]) continue;
        if(!MAP[nxtY][nxtX]) continue;

        visited[nxtY][nxtX] = true;
        currDist++;
        dfs(nxtY, nxtX);
        currDist--;
        visited[nxtY][nxtX] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> k;
    char tmp;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> tmp;
            MAP[i][j] = (tmp == '.' ? true : false);
        }
    }

    currDist = 1;
    visited[r-1][0] = true;
    dfs(r-1, 0);

    cout << Answer;

    return 0;
}

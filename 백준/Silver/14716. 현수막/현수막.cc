#include <bits/stdc++.h>
#define MAX 250
using namespace std;

int m, n;
vector<vector<int>> banner(MAX, vector<int>(MAX));
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
int Answer;

int dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void dfs(int y, int x){

    for(int i=0; i<9; i++){
        int nxtY = y + dy[i];
        int nxtX = x + dx[i];

        if(nxtY < 0 || nxtY >= m) continue;
        if(nxtX < 0 || nxtX >= n) continue;
        if(visited[nxtY][nxtX]) continue;
        if(!banner[nxtY][nxtX]) continue;

        visited[nxtY][nxtX] = true;
        dfs(nxtY, nxtX);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> banner[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(banner[i][j] && !visited[i][j]){
                visited[i][j] = true;
                dfs(i, j);
                Answer++;
            }
        }
    }

    cout << Answer;

    return 0;
}

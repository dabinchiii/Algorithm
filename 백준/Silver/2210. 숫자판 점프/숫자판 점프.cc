#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board(5, vector<int>(5));
int currNum;
set<int> Answer;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int fac){

    if(fac < 1){
        Answer.insert(currNum);
        return;
    }

    for(int i=0; i<4; i++){
        int nxtY = y + dy[i];
        int nxtX = x + dx[i];

        if(nxtY < 0 || nxtY >= 5) continue;
        if(nxtX < 0 || nxtX >= 5) continue;

        int tmp = board[nxtY][nxtX] * fac;
        currNum += tmp;
        dfs(nxtY, nxtX, fac/10);
        currNum -= tmp;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            currNum = board[i][j] * 100000;
            dfs(i, j, 10000);
        }
    }

    cout << Answer.size();

    return 0;
}

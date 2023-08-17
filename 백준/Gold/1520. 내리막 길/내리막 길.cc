// DFS + DP
#include <bits/stdc++.h>
#define MAX 500
using namespace std;

int m, n;
vector<vector<int>> mp(MAX, vector<int>(MAX));
vector<vector<int>> dp(MAX, vector<int>(MAX, -1));
vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int currY, int currX){
    dp[currY][currX] = 0; // 방문

    for(int i=0; i<4; i++){
        int nxtY = currY + dir[i][0];
        int nxtX = currX + dir[i][1];

        if(nxtY < 0 || nxtY >= m) continue;
        if(nxtX < 0 || nxtX >= n) continue;
        if(mp[nxtY][nxtX] >= mp[currY][currX]) continue;

        if(dp[nxtY][nxtX] != -1){ // 이미 방문한 곳
            dp[currY][currX] += dp[nxtY][nxtX];
        }
        else{ // 아직 방문하지 않은 곳
            dp[currY][currX] += dfs(nxtY, nxtX);
        }
    }

    return dp[currY][currX];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> mp[i][j];
        }
    }

    dp[m-1][n-1] = 1;
    cout << dfs(0, 0);

    return 0;
}

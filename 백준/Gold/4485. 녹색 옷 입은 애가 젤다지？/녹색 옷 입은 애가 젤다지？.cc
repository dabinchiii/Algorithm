#include <bits/stdc++.h>
#define INF 400000

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve(int n, int test_case){
    vector<vector<int>> cost(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> dis(n, vector<int>(n, INF));
    queue<pair<int, int>> q;

    q.push({0, 0});
    dis[0][0] = cost[0][0];

    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= n) continue;

            if(dis[currX][currY] + cost[nxtX][nxtY] < dis[nxtX][nxtY]){
                dis[nxtX][nxtY] = dis[currX][currY] + cost[nxtX][nxtY];
                q.push({nxtX, nxtY});
            }
        }
    }


    cout << "Problem " << test_case << ": " << dis[n - 1][n - 1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case = 0, n;
    while(1){
        cin >> n;
        if(n == 0) break;

        solve(n, ++test_case);
    }

    return 0;
}

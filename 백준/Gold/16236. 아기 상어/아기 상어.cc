#include <bits/stdc++.h>

using namespace std;

int n;
int board[20][20];
int ans;

int sharkX, sharkY, sharkSize;
vector<pair<int, int>> fish;
int closestDis, cntFish;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void findFish(){
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    q.push({{sharkX, sharkY}, 0});
    visited[sharkX][sharkY] = true;

    closestDis = -1;

    while(!q.empty()){
        int currX = q.front().first.first;
        int currY = q.front().first.second;
        int currDis = q.front().second;
        q.pop();

        if(closestDis != -1 && currDis > closestDis) break;

        if(board[currX][currY] > 0 && board[currX][currY] < sharkSize){
            if(closestDis == -1){
                closestDis = currDis;
            }
            fish.push_back({currX, currY});
        }

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= n) continue;
            if(visited[nxtX][nxtY]) continue;
            if(board[nxtX][nxtY] > sharkSize) continue;

            visited[nxtX][nxtY] = true;
            q.push({{nxtX, nxtY}, currDis + 1});
        }

    }

    return;
}

void eatFish(){
    sort(fish.begin(), fish.end());

    int fishX = fish[0].first;
    int fishY = fish[0].second;

    ans += closestDis;
    sharkX = fishX;
    sharkY = fishY;

    board[fishX][fishY] = 0;
    cntFish++;

    if(cntFish == sharkSize){
        sharkSize++;
        cntFish = 0;
    }

    fish.clear();

    return;
}

void solve(){
    sharkSize = 2;
    cntFish = 0;

    while(true){
        findFish();

        if(fish.empty()) break;

        eatFish();
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j] == 9){
                sharkX = i;
                sharkY = j;
                board[i][j] = 0;
            }
        }
    }

    solve();

    cout << ans;

    return 0;
}

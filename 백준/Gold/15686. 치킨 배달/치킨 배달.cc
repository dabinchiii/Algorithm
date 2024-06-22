#include <bits/stdc++.h>
#define MAX_N 50
#define MAX_M 13

using namespace std;

int n, m;
vector<pair<int, int>> house, chicken;
int board[MAX_N][MAX_N];
int sel[MAX_M + 1];
int ans;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int getHouseChickenDist(int idx){
    int dis = 2500;

    int hx = house[idx].first;
    int hy = house[idx].second;

    int cx, cy;
    for(int i=1; i<=m; i++){
        cx = chicken[sel[i]].first;
        cy = chicken[sel[i]].second;
        dis = min(dis, abs(hx - cx) + abs(hy - cy));
    }

    return dis;
}

int getCityChickenDist(){
    int sum = 0;
    for(int i=0; i<house.size(); i++){
        sum += getHouseChickenDist(i);
    }

    return sum;
}

void bt(int curr){
    if(curr == m + 1){
        ans = min(ans, getCityChickenDist());
        return;
    }

    for(int i=sel[curr - 1] + 1; i<chicken.size(); i++){
        sel[curr] = i;
        bt(curr + 1);
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];

            if(board[i][j] == 1){
                house.push_back({i, j});
            }
            else if(board[i][j] == 2){
                chicken.push_back({i, j});
            }
        }
    }

    sel[0] = -1;
    ans = 50000; // > 13 * 50 * 50

    bt(1);

    cout << ans;

    return 0;
}

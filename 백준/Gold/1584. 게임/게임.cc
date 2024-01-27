#include <bits/stdc++.h>
#define MAX 500
#define INF 25000

using namespace std;

vector<vector<int>> area(MAX + 1, vector<int>(MAX + 1, 0));
vector<vector<int>> damage(MAX + 1, vector<int>(MAX + 1, INF));

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve(){
    priority_queue<pair<int, pair<int, int>>> q;

    q.push({0, {0, 0}});
    damage[0][0] = 0;

    while(!q.empty()){
        int currX = q.top().second.first;
        int currY = q.top().second.second;
        int currDamage = -q.top().first;
        q.pop();

        if(damage[currX][currY] < currDamage) continue;

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX > MAX) continue;
            if(nxtY < 0 || nxtY > MAX) continue;
            if(area[nxtX][nxtY] == INF) continue;

            int nxtDamage = currDamage + area[nxtX][nxtY];

            if(damage[nxtX][nxtY] > nxtDamage){
                damage[nxtX][nxtY] = nxtDamage;
                q.push({-nxtDamage, {nxtX, nxtY}});
            }
        }
    }

    return;
}

void setArea(int x1, int y1, int x2, int y2, int x){
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);

    for(int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            area[i][j] = x;
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int x1, y1, x2, y2;
    for(int i=0; i<n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        setArea(x1, y1, x2, y2, 1);
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        setArea(x1, y1, x2, y2, INF);
    }

    solve();

    cout << (damage[MAX][MAX] == INF ? -1 : damage[MAX][MAX]);

    return 0;
}

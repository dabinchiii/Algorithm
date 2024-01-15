#include <bits/stdc++.h>
#define INF 400000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    vector<vector<int>> dis(v + 1, vector<int>(v + 1, INF));
    for(int i=1; i<=v; i++){
        dis[i][i] = 0;
    }
    int a, b, c;
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        dis[a][b] = c;
    }

    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int Answer = INF;
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(i == j) continue;
            Answer = min(Answer, dis[i][j] + dis[j][i]);
        }
    }

    cout << (Answer == INF ? -1 : Answer);

    return 0;
}

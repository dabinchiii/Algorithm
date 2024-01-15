#include <bits/stdc++.h>
#define INF 10000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF));
    for(int i=1; i<=n; i++){
        cost[i][i] = 0;
    }
    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(cost[i][j] == INF) cout << 0 << ' ';
            else cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

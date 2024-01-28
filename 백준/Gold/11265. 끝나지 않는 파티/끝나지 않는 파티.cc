#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> w(n + 1, vector<int>(n + 1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> w[i][j];
        }
    }

    vector<vector<int>> dis = w;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        cout << (dis[a][b] <= c ? "Enjoy other party" : "Stay here") << '\n';
    }

    return 0;
}

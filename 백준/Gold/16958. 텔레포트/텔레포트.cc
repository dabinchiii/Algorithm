#include <bits/stdc++.h>
#define INF 2000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    vector<bool> isSpecial(n + 1);
    vector<pair<int, int>> city(n + 1);

    int s, x, y;
    for(int i=1; i<=n; i++){
        cin >> s >> x >> y;
        city[i] = {x, y};
        isSpecial[i] = (s == 1 ? true : false);
    }

    vector<vector<int>> w(n + 1, vector<int>(n + 1, INF));
    for(int i=1; i<=n; i++){
        w[i][i] = 0;
        for(int j=i + 1; j<=n; j++){
            if(isSpecial[i] && isSpecial[j]){
                w[i][j] = w[j][i] = t;
            }
            int rt = abs(city[i].first - city[j].first);
            int ct = abs(city[i].second - city[j].second);
            w[i][j] = w[j][i] = min(w[i][j], rt + ct);
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

    int m;
    cin >> m;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        cout << dis[a][b] << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
#define INF 100

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> w(n + 1, vector<int>(n + 1, INF));

    for(int i=1; i<=n; i++) w[i][i] = 0;

    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        w[a][b] = w[b][a] = 1;
    }

    vector<vector<int>> dis = w;

    for(int m=1; m<=n; m++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j] = min(dis[i][j], dis[i][m] + dis[m][j]);
            }
        }
    }

    bool Answer = true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dis[i][j] > 6) Answer = false;
        }
    }
    cout << (Answer ? "Small World!" : "Big World!");

    return 0;
}

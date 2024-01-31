#include <bits/stdc++.h>
#define INF 200000

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> w(n + 1, vector<int>(n + 1, INF));
    for(int i=1; i<=n; i++) w[i][i] = 0;

    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        w[a][b] = w[b][a] = c;
    }

    vector<vector<int>> first(n + 1, vector<int>(n + 1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            first[i][j] = j;
        }
    }

    vector<vector<int>> dis = w;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dis[i][j] <= dis[i][k] + dis[k][j]) continue;
                dis[i][j] = dis[i][k] + dis[k][j];
                first[i][j] = first[i][k];
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) cout << "- ";
            else cout << first[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

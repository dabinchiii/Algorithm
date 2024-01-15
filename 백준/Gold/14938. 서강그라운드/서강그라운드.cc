#include <bits/stdc++.h>
#define INF 15000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> item(n + 1);
    for(int i=1; i<=n; i++){
        cin >> item[i];
    }

    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
    for(int i=1; i<=n; i++){
        dis[i][i] = 0;
    }

    int a, b, l;
    for(int i=0; i<r; i++){
        cin >> a >> b >> l;
        dis[a][b] = dis[b][a] = l;
    }

    for(int k = 1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    vector<int> cntGet(n + 1, 0);
    int Answer = -1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dis[i][j] <= m) cntGet[i] += item[j];
        }
        Answer = max(Answer, cntGet[i]);
    }

    cout << Answer;

    return 0;
}

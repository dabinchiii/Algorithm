#include <bits/stdc++.h>
#define INF 100000

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> w(n + 1, vector<int>(n + 1, INF));
    for(int i=1; i<=n; i++) w[i][i] = 0;

    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        w[a][b] = c;
        w[b][a] = c;
    }

    int k;
    cin >> k;
    vector<int> pt(k);
    for(int i=0; i<k; i++){
        cin >> pt[i];
    }
    sort(pt.begin(), pt.end());

    vector<vector<int>> dis = w;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int minValue = INF, Answer = -1;
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int x : pt){
            sum += dis[x][i];
        }

        if(sum < minValue){
            minValue = sum;
            Answer = i;
        }
    }

    cout << Answer << '\n';

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        solve();
    }

    return 0;
}

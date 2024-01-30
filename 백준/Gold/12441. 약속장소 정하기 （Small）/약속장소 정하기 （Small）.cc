#include <bits/stdc++.h>
#define INF 22000

using namespace std;

void solve(int tc){
    int n, p, m;
    cin >> n >> p >> m;

    vector<pair<int, int>> f(p);
    for(int i=0; i<p; i++){
        cin >> f[i].first >> f[i].second;
    }

    vector<vector<int>> w(n + 1, vector<int>(n + 1, INF));
    for(int i=1; i<=n; i++) w[i][i] = 0;

    for(int i=0; i<m; i++){
        int d, l, prev, curr;
        cin >> d >> l;

        cin >> prev;
        for(int j=0; j<l-1; j++){
            cin >> curr;
            w[prev][curr] = w[curr][prev] = d;
            prev = curr;
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

    int Answer = INF;
    for(int i=1; i<=n; i++){
        int maxT = -1;
        for(pair<int, int> x : f){
            maxT = max(maxT, x.second * dis[x.first][i]);
        }
        Answer = min(Answer, maxT);
    }

    cout << "Case #" << tc << ": " << (Answer == INF ? -1 : Answer) << '\n';

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        solve(t);
    }

    return 0;
}

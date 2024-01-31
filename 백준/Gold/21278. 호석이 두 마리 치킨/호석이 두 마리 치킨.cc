#include <bits/stdc++.h>
#define INF 10000

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> w(n + 1, vector<int>(n + 1, INF));
    for(int i=1; i<=n; i++) w[i][i] = 0;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        w[a][b] = w[b][a] = 1;
    }

    vector<vector<int>> dis = w;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int AnswerT = INF;
    pair<int, int> AnswerCity;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            int t = 0;
            for(int k=1; k<=n; k++){
                t += min(dis[i][k], dis[j][k]);
            }

            if(t < AnswerT){
                AnswerT = t;
                AnswerCity = {i, j};
            }
        }
    }
    AnswerT *= 2; // 왕복

    cout << AnswerCity.first << ' ' << AnswerCity.second << ' ' << AnswerT;

    return 0;
}

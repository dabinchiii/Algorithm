#include <bits/stdc++.h>
#define INF 10000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> relation(n + 1, vector<int>(n + 1, INF));
    for(int i=1; i<=n; i++) relation[i][i] = 0;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }

    vector<vector<int>> dis = relation;
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
        for(int j=1; j<=n; j++){
            sum += dis[i][j];
        }

        if(sum < minValue){
            minValue = sum;
            Answer = i;
        }
    }

    cout << Answer;

    return 0;
}

#include <bits/stdc++.h>
#define INF 500

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> order(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> rvOrder(n + 1, vector<int>(n + 1, INF));
    for(int i=1; i<=n; i++){
        order[i][i] = rvOrder[i][i] = 0;
    }
    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        order[a][b] = 1;
        rvOrder[b][a] = 1;
    }

    for(int x=1; x<=n; x++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                order[i][j] = min(order[i][j], order[i][x] + order[x][j]);
                rvOrder[i][j] = min(rvOrder[i][j], rvOrder[i][x] + rvOrder[x][j]);
            }
        }
    }

    int s, Answer;
    cin >> s;
    for(int i=0; i<s; i++){
        cin >> a >> b;

        if(order[a][b] != INF) Answer = -1;
        else if(rvOrder[a][b] != INF) Answer = 1;
        else Answer = 0;

        cout << Answer << '\n';
    }

    return 0;
}

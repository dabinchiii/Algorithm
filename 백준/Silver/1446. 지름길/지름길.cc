#include <bits/stdc++.h>
#define INF 10000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<vector<int>> w(d + 1, vector<int>(d + 1, INF));

    for(int i=0; i<=d; i++){
        for(int j=i; j<=d; j++){
            w[i][j] = j - i;
        }
    }

    int a, b, l;
    for(int i=0; i<n; i++){
        cin >> a >> b >> l;
        if(b > d) continue;
        w[a][b] = min(w[a][b], l);
    }

    vector<bool> visited(d + 1, false);
    vector<int> dis(d + 1, INF);

    dis[0] = 0;
    visited[0] = 0;

    for(int i=1; i<=d - 1; i++){
        int minValue = INF, minNode = -1;
        for(int j=0; j<=d; j++){
            if(visited[j]) continue;
            if(dis[j] < minValue){
                minNode = j;
                minValue = dis[j];
            }
        }

        visited[minNode] = true;
        for(int j=0; j<=d; j++){
            if(visited[j]) continue;
            dis[j] = min(dis[j], dis[minNode] + w[minNode][j]);
        }
    }

    cout << dis[d];

    return 0;
}

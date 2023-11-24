#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, m;
    cin >> n >> s >> m;

    vector<int> arr(n + 1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    vector<vector<bool>> visited(n+1, vector<bool>(m + 1, false));
    visited[0][s] = true;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(!visited[i-1][j]) continue;

            int down = j - arr[i];
            int up = j + arr[i];

            if(down >= 0) visited[i][down] = true;
            if(up <= m) visited[i][up] = true;
        }
    }

    int Answer = -1;
    for(int i=0; i<=m; i++){
        if(visited[n][i]) Answer = max(Answer, i);
    }

    cout << Answer;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b){
    return {a.first + b.first, a.second + b.second};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> campus(n, vector<char>(m));
    pair<int, int> dy; // 도연
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> campus[i][j];
            if(campus[i][j] == 'I'){
                dy = {i, j};
            }
        }
    }

    int Answer = 0;
    pair<int, int> pos[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    q.push(dy);
    visited[dy.first][dy.second] = true;

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            pair<int, int> nxt = curr + pos[i];

            if(nxt.first < 0 || nxt.first >= n) continue;
            if(nxt.second < 0 || nxt.second >= m) continue;
            if(campus[nxt.first][nxt.second] == 'X') continue;
            if(visited[nxt.first][nxt.second]) continue;

            if(campus[nxt.first][nxt.second] == 'P') Answer++;
            visited[nxt.first][nxt.second] = true;
            q.push(nxt);
        }
    }



    if(Answer > 0) cout << Answer;
    else cout << "TT";

    return 0;
}

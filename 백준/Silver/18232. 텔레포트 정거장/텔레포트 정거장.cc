#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int s, e;
    cin >> s >> e;

    vector<vector<int>> t(n + 1);
    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        t[x].push_back(y);
        t[y].push_back(x);
    }

    int Answer = -1;
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;

    q.push({s, 0});
    visited[s] = true;

    while(!q.empty()){
        int currX = q.front().first;
        int currT = q.front().second;
        q.pop();

        if(currX == e){
            Answer = currT;
            break;
        }

        if(currX + 1 <= n && !visited[currX + 1]){
            visited[currX + 1] = true;
            q.push({currX + 1, currT + 1});
        }
        if(currX - 1 >= 1 && !visited[currX - 1]){
            visited[currX - 1] = true;
            q.push({currX - 1, currT + 1});
        }

        for(int nxt : t[currX]){
            if(visited[nxt]) continue;
            visited[nxt] = true;
            q.push({nxt, currT + 1});
        }
    }

    cout << Answer;

    return 0;
}

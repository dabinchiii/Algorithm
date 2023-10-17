#include <bits/stdc++.h>
#define MAX_N 5000
using namespace std;

int n;
vector<vector<pair<int, int>>> g(MAX_N + 1);
vector<bool> visited(MAX_N + 1);
long long Answer;

void dfs(int curr, long long dist){
    visited[curr] = true;
    Answer = max(Answer, dist);

    for(int i=0; i<g[curr].size(); i++){
        int nxt = g[curr][i].first;
        if(!visited[nxt]){
            dfs(nxt, dist + g[curr][i].second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int a, b, c;
    for(int i=0; i<n-1; i++){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    dfs(1, 0); // 입구는 1번

    cout << Answer;

    return 0;
}

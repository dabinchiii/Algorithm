#include <bits/stdc++.h>
#define MAX_N 500
using namespace std;

int n, m;
vector<vector<int>> g(MAX_N + 1);
vector<bool> visited(MAX_N + 1);
int cntNode, cntEdge;
int Answer;

void init(){
    Answer = 0;
    for(int i=1; i<=n; i++){
        g[i].clear();
        visited[i] = false;
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cntNode = 0;
    cntEdge = 0;
    while(!q.empty()){
        cntNode++;
        int curr = q.front();
        q.pop();

        for(int nxt : g[curr]){
            cntEdge++;
            if(!visited[nxt]){
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    if(cntNode -1 == cntEdge / 2) Answer++;
}

void solve(){
    init();

    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case = 0;
    while(true){
        test_case++;
        cin >> n >> m;

        if(n == 0 && m == 0) break;

        solve();

        cout << "Case " << test_case << ": ";
        if(Answer == 0) cout << "No trees." << '\n';
        else if(Answer == 1) cout << "There is one tree." << '\n';
        else cout << "A forest of " << Answer << " trees." << '\n';
    }

    return 0;
}

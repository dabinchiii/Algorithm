#include <bits/stdc++.h>
#define MAX_V 200000
using namespace std;

int v, e;
vector<vector<int>> g(MAX_V + 1);
vector<int> visited(MAX_V + 1);
bool Answer;

void init(){
    for(int i=1; i<=v; i++){
        g[i].clear();
        visited[i] = -1;
    }
    Answer = true;
}

void dfs(int currV){
    for(int nxt : g[currV]){
        if(visited[nxt] == -1){
            visited[nxt] = (visited[currV] + 1) % 2;
            dfs(nxt);
        }
    }
}

bool isBipartiteGraph(){
    for(int i=1; i<=v; i++){
        for(int nxt : g[i]){
            if(visited[i] == visited[nxt]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    for(int test_case=0; test_case<k; test_case++){
        cin >> v >> e;

        init();

        int a, b; // u, v
        for(int i=0; i<e; i++){
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        for(int i=1; i<=v; i++){
            if(visited[i] == -1){
                visited[i] = 0;
                dfs(i);
            }
        }

        Answer = isBipartiteGraph();

        cout << (Answer ? "YES" : "NO") << '\n';
    }

    return 0;
}

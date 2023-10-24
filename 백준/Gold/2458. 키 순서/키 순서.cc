#include <bits/stdc++.h>
#define MAX_N 500
using namespace std;

int n, m;
vector<vector<int>> taller(MAX_N + 1);
vector<vector<int>> shorter(MAX_N + 1);
int Answer;

void solve(int target){
    vector<bool> visited(n+1, false);
    int cnt = 0;

    queue<int> q;
    q.push(target);
    visited[target] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int nxt : taller[curr]){
            if(!visited[nxt]){
                visited[nxt] = true;
                cnt++;
                q.push(nxt);
            }
        }
    }

    q.push(target);
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int nxt : shorter[curr]){
            if(!visited[nxt]){
                visited[nxt] = true;
                cnt++;
                q.push(nxt);
            }
        }
    }

    if(cnt == n - 1) Answer++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        taller[a].push_back(b);
        shorter[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        solve(i);
    }

    cout << Answer;

    return 0;
}

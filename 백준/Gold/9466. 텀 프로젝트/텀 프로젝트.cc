#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

int n;
int s[MAX_N + 1];
bool visited[MAX_N + 1], done[MAX_N + 1];
int ans;

void init(){
    for(int i=1; i<=n; i++){
        visited[i] = false;
        done[i] = false;
    }
    ans = n;

    return;
}

void dfs(int curr){
    visited[curr] = true;
    int nxt = s[curr];

    if(!visited[nxt]) dfs(nxt);
    else if(!done[nxt]){
        ans--;
        for(int i=nxt; i!=curr; i=s[i]){
            ans--;
        }
    }

    done[curr] = true;

    return;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }

    init();
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        dfs(i);
    }

    cout << ans << '\n';

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        solve();
    }

    return 0;
}

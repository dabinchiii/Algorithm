#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[8], arr[8];
bool visited[8];

void dfs(int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++) cout << num[arr[i]] << ' ';
        cout << '\n';

        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;

        arr[cnt] = i;
        visited[i] = true;

        dfs(cnt + 1);

        visited[i] = false;
    }

    return;
}

void solve(){
    sort(num, num + n);

    dfs(0);

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    solve();

    return 0;
}

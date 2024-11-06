#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8];

void dfs(int cnt, int left){
    if(cnt == m){
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';

        return;
    }

    for(int i=left; i<=n; i++){
        arr[cnt] = i;
        dfs(cnt + 1, i);
    }

    return;
}

void solve(){
    dfs(0, 1);

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    solve();

    return 0;
}

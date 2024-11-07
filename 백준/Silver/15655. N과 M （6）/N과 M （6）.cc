#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[8], arr[8];

void dfs(int cnt, int left){
    if(cnt == m){
        for(int i=0; i<m; i++) cout << num[arr[i]] << ' ';
        cout << '\n';

        return;
    }

    for(int i=left; i<n; i++){
        arr[cnt] = i;
        dfs(cnt + 1, i + 1);
    }

    return;
}

void solve(){
    sort(num, num + n);

    dfs(0, 0);

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

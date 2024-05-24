#include <bits/stdc++.h>
#define MAX_M 8

using namespace std;

int n, m;
int ans[MAX_M];

void bt(int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=ans[max(0, cnt - 1)] + 1; i<=n; i++){
        ans[cnt] = i;
        bt(cnt + 1);
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    bt(0);

    return 0;
}

#include <bits/stdc++.h>
#define MAX_M 8

using namespace std;

int n, m;
int ans[MAX_M];

void bt(int cnt, int left){
    if(cnt == m){
        for(int i=0; i<m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=left; i<=n; i++){
        ans[cnt] = i;
        bt(cnt + 1, i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    bt(0, 1);

    return 0;
}

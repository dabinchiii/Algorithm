#include <bits/stdc++.h>
#define MAX_N 8
#define MAX_M 8

using namespace std;

int n, m;
int arr[MAX_N], ans[MAX_M];
bool visited[MAX_N];

void bt(int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;

        ans[cnt] = arr[i];

        visited[i] = true;
        bt(cnt + 1);
        visited[i] = false;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    bt(0);

    return 0;
}

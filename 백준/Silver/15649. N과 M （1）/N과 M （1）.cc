#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8];
bool visited[8];

void f(int k){
    if(k == m){
        for(int i=0; i<m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
    }

    for(int i=1; i<=n; i++){
        if(visited[i]) continue;

        arr[k] = i;
        visited[i] = true;
        f(k+1);
        visited[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    f(0);

    return 0;
}

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
        return;
    }

    for(int i=1; i<=n; i++){
        arr[k] = i;
        f(k+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    f(0);

    return 0;
}

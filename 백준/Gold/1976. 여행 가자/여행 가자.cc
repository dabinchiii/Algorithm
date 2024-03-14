#include <bits/stdc++.h>
#define MAX_N 200

using namespace std;

int n, m;
int parent[MAX_N + 1];

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}
void makeUnion(int x, int y){
    x = findParent(x);
    y = findParent(y);
    parent[y] = x ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int g[n + 1][n + 1];
    for(int i=1; i<=n; i++){
        parent[i] = i;
        for(int j=1; j<=n; j++){
            cin >> g[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=i + 1; j<=n; j++){
            if(g[i][j]) makeUnion(i, j);
        }
    }

    int path[m];
    for(int i=0; i<m; i++){
        cin >> path[i];
    }

    bool Answer = true;
    for(int i=1; i<m; i++){
        if(findParent(path[i - 1]) != findParent(path[i])){
            Answer = false;
            break;
        }
    }

    cout << (Answer ? "YES" : "NO");

    return 0;
}

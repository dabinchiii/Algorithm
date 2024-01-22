#include <bits/stdc++.h>
#define MAX_N 1000000

using namespace std;

int n, m;
vector<int> parent(MAX_N + 1, -1);

int findRoot(int x){
    if(parent[x] == -1) return x;
    parent[x] = findRoot(parent[x]);
    return parent[x];
}

void makeUnion(int a, int b){
    if(a > b) swap(a, b);

    int rootA = findRoot(a);
    int rootB = findRoot(b);

    if(rootA != rootB) parent[rootB] = rootA;

    return;
}
bool isUnion(int a, int b){
    return findRoot(a) == findRoot(b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int command, a, b;
    for(int i=0; i<m; i++){
        cin >> command >> a >> b;

        if(command == 0) makeUnion(a, b);
        else cout << (isUnion(a, b) ? "YES" : "NO") << '\n';
    }

    return 0;
}

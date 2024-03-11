#include <bits/stdc++.h>
#define MAX_M 200000

using namespace std;

int m, n;
vector<pair<int, pair<int, int>>> e;
int parent[MAX_M];
int Answer;

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}
void makeUnion(int x, int y){
    x = findParent(x);
    y = findParent(y);
    parent[y] = x;
}

void kruskal(){
    sort(e.begin(), e.end());
    for(int i=0; i<m; i++) parent[i] = i;

    for(int i=0; i<e.size(); i++){
        int u = e[i].second.first;
        int v = e[i].second.second;
        if(findParent(u) == findParent(v)) continue;

        makeUnion(u, v);
        Answer -= e[i].first;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        e.clear();
        Answer = 0;

        cin >> m >> n;
        if(m == 0) break;

        int x, y, z;
        for(int i=0; i<n; i++){
            cin >> x >> y >> z;
            e.push_back({z, {x, y}});
            Answer += z;
        }

        kruskal();

        cout << Answer << '\n';
    }

    return 0;
}

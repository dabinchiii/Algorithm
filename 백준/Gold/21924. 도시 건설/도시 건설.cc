#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> e;
int parent[MAX_N + 1];
int cntEdge;
long long Answer;

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
    for(int i=1; i<=n; i++) parent[i] = i;

    for(int i=0; i<e.size(); i++){
        int u = e[i].second.first;
        int v = e[i].second.second;
        if(findParent(u) == findParent(v)) continue;

        makeUnion(u, v);
        Answer -= e[i].first;
        cntEdge++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b, c;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        e.push_back({c, {a, b}});
        Answer += c;
    }

    kruskal();

    cout << (cntEdge != n - 1 ? -1 : Answer);

    return 0;
}

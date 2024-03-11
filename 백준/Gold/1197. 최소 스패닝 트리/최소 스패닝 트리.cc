#include <bits/stdc++.h>
#define MAX_V 10000

using namespace std;

int v, e;
vector<pair<int, pair<int, int>>> edges;
int parent[MAX_V + 1];
int Answer;

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void makeUnion(int x, int y){
    x = findParent(x);
    y = findParent(y);

    parent[y] = x;

    return;
}

void kruskal(){
    sort(edges.begin(), edges.end());

    for(int i=1; i<=v; i++){
        parent[i] = i;
    }

    for(int i=0; i<e; i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(findParent(u) == findParent(v)) continue;

        makeUnion(u, v);
        Answer += edges[i].first;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;

    int a, b, c;
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    kruskal();

    cout << Answer;

    return 0;
}

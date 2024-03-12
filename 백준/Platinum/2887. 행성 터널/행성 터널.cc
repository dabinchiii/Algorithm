#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

int n;
vector<pair<int, int>> v[3];
vector<pair<int, pair<int, int>>> e;
int parent[MAX_N];
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

    for(int i=0; i<n; i++) parent[i] = i;

    for(int i=0; i<e.size(); i++){
        int u = e[i].second.first;
        int v = e[i].second.second;
        if(findParent(u) == findParent(v)) continue;

        makeUnion(u, v);
        Answer += e[i].first;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int x, y, z;
    for(int i=0; i<n; i++){
        cin >> x >> y >> z;

        v[0].push_back({x, i});
        v[1].push_back({y, i});
        v[2].push_back({z, i});
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());

    int dx, dy, dz;
    for(int i=0; i<n - 1; i++){
        dx = abs(v[0][i].first - v[0][i + 1].first);
        dy = abs(v[1][i].first - v[1][i + 1].first);
        dz = abs(v[2][i].first - v[2][i + 1].first);

        e.push_back({dx, {v[0][i].second, v[0][i + 1].second}});
        e.push_back({dy, {v[1][i].second, v[1][i + 1].second}});
        e.push_back({dz, {v[2][i].second, v[2][i + 1].second}});
    }

    kruskal();

    cout << Answer;

    return 0;
}

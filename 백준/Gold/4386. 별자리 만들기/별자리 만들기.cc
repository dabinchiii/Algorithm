#include <bits/stdc++.h>
#define MAX_N 100

using namespace std;

int n;
pair<double, double> star[MAX_N + 1];
vector<pair<double, pair<int, int>>> e;
int parent[MAX_N + 1];
double Answer;

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
        Answer += e[i].first;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> star[i].first >> star[i].second;
    }

    double dx, dy, dis;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            dx = abs(star[i].first - star[j].first);
            dy = abs(star[i].second - star[j].second);
            dis = sqrt(dx * dx + dy * dy);

            e.push_back({dis, {i, j}});
        }
    }

    kruskal();

    cout << fixed;
    cout.precision(2);

    cout << Answer;

    return 0;
}

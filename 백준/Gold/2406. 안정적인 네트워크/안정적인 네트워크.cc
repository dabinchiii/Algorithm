#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000

using namespace std;

struct node{
    int w, u, v;
};

bool cmp(const node &a, const node &b){
    return a.w < b.w;
}

int N, M;
vector<node> edges;
int parent[MAX_N + 1];
int ansCost;
vector<pair<int, int>> ansPairs;

void makeSet(){
    for(int i=1; i<=N; i++) parent[i] = i;
}
int findRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]);
}
bool makeUnion(int a, int b){
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rootA == rootB) return false;
    parent[rootA] = rootB;
    return true;
}

void solve(){ // 2~N번 노드에 대해 mst 만들어야 함.
    sort(edges.begin(), edges.end(), cmp);
    
    for(auto &curr : edges){
        if(makeUnion(curr.u, curr.v)){
            ansCost += curr.w;
            ansPairs.push_back({curr.u, curr.v});
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    makeSet();
    
    int u, v;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        makeUnion(u, v);
    }
    
    int w;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> w;
            if(i != 1 && j != 1 && i < j) edges.push_back({w, i, j});
        }
    }
    
    solve();
    
    cout << ansCost << ' ' << ansPairs.size() << '\n';
    for(auto &curr : ansPairs) cout << curr.first << ' ' << curr.second << '\n';
    
    return 0;
}

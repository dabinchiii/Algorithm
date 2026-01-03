#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000
#define MAX_K 1000000

using namespace std;

struct edgeNode{
    int w, u, v;
};

int N, M, s, e;
vector<edgeNode> edges;
int parent[MAX_N + 1], rnk[MAX_N + 1];
int ans;

bool cmp(edgeNode &a, edgeNode &b){
    return a.w > b.w;
}

void makeSet(){
    for(int i=1; i<=N; i++) parent[i] = i;
}
int findRoot(int x){
    while(parent[x] != x) x = parent[x];
    return x;
}
bool makeUnion(int a, int b){
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    
    if(rootA == rootB) return false;
    
    if(rnk[rootA] < rnk[rootB]){
        parent[rootA] = rootB;
    }
    else if(rnk[rootB] < rnk[rootA]){
        parent[rootB] = rootA;
    }
    else{
        parent[rootB] = rootA;
        ++rnk[rootA];
    }
    
    return findRoot(s) == findRoot(e);
}

void solve(){
    sort(edges.begin(), edges.end(), cmp);
    makeSet();
    
    for(auto curr : edges){
        if (makeUnion(curr.u, curr.v)) {
            ans = curr.w;
            return;
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> s >> e;
    
    int u, v, k;
    for(int i=0; i<M; i++){
        cin >> u >> v >> k;
        edges.push_back({k, u, v});
    }
    
    solve();
    cout << ans;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000
#define MAX_K 1000000

#define min(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

int N, M, s, e;
vector<pair<int, pair<int, int>>> edges;
int parent[MAX_N + 1];
int ans;

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
bool isConnected(){
    int rootS = findRoot(s);
    int rootE = findRoot(e);
    return rootS == rootE;
}

void solve(){
    sort(edges.begin(), edges.end(), greater<>());
    makeSet();
    
    int maxW = MAX_K;
    for(auto curr : edges){
        if(makeUnion(curr.second.first, curr.second.second)){
            maxW = min(maxW, curr.first);
            
            if(isConnected()){
                ans = maxW;
                return;
            }
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
        edges.push_back({k, {u, v}});
    }
    
    solve();
    cout << ans;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10000
#define INF 1000000005

using namespace std;

int N, M;
bool isM[MAX_N + 1];
vector<pair<int, pair<int, int>>> edges;
int parent[MAX_N + 1];
int ans;

int findRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]);
    
}
bool isUnion(int x, int y){
    return findRoot(x) == findRoot(y);
}
void makeUnion(int x, int y){
    x = findRoot(x);
    y = findRoot(y);
    
    if(x != y) parent[x] = y;
    
    return;
}

void solve(){
    sort(edges.begin(), edges.end());
    
    for(int i=1; i<=N; i++) parent[i] = i;
    
    for(auto curr : edges){
        int u = curr.second.first;
        int v = curr.second.second;
        
        if(isUnion(u, v)) continue;
        
        makeUnion(u, v);
        ans += curr.first;
    }
    
    int root = findRoot(1);
    for(int i=2; i<=N; i++){
        if(findRoot(i) != root){
            ans = -1;
            return;
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    char ch;
    for(int i=1; i<=N; i++){
        cin >> ch;
        if(ch == 'M') isM[i] = true;
    }
    
    int u, v, d;
    for(int i=0; i<M; i++){
        cin >> u >> v >> d;
        if(isM[u] == isM[v]) continue;
        edges.push_back({d, {u, v}});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

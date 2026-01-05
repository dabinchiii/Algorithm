#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10000

using namespace std;

struct edgeNode{
    int w, u, v;
};
bool cmp(const edgeNode &a, const edgeNode &b){
    return a.w > b.w;
}

int N, M;
int parent[MAX_N + 1];
vector<edgeNode> edges;
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

void solve(){
    sort(edges.begin(), edges.end(), cmp);
    
    for(auto &curr : edges){
        if(!makeUnion(curr.u, curr.v)){
            ans += curr.w;
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    makeSet();
    
    int a, b, c, d;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c >> d;
        
        if(d) makeUnion(a, b);
        else edges.push_back({c, a, b});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 200000

using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> edges;
int parent[MAX_N + 1]; // 0번 노드가 출구
int ans;

void makeSet(){
    for(int i=0; i<=N; i++) parent[i] = i;
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
    int cnt = 0;
    
    sort(edges.begin(), edges.end());
    makeSet();
    
    for(auto curr : edges){
        if(cnt >= N) break; // 출구 포함하면 N + 1개 노드 연결하는 mst 만들어야함
        
        if(makeUnion(curr.second.first, curr.second.second)){
            ans += curr.first;
            ++cnt;
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    int a, b, c, t;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    for(int i=1; i<=N; i++){
        cin >> t;
        edges.push_back({t, {0, i}});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

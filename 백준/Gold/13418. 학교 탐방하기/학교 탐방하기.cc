#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int N, M;
int entCost;
vector<pair<int, pair<int, int>>> edges;
int parent[MAX_N + 1];
long long ans;

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

long long getWorst(){
    long long cost = entCost;
    int cnt = 0;
    
    makeSet();
    
    for(int i=M - 1; i>=0 && cnt < N - 1; i--){
        if(makeUnion(edges[i].second.first, edges[i].second.second)){
            cost += edges[i].first;
            ++cnt;
        }
    }
    
    return cost * cost;
}

long long getBest(){
    long long cost = entCost;
    int cnt = 0;
    
    makeSet();
    
    for(int i=0; i<M && cnt < N - 1; i++){
        if(makeUnion(edges[i].second.first, edges[i].second.second)){
            cost += edges[i].first;
            ++cnt;
        }
    }
    
    return cost * cost;
}

void solve(){
    sort(edges.begin(), edges.end());
    ans = getWorst() - getBest();
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    int a, b, c;
    cin >> a >> b >> c;
    entCost = c == 0 ? 1 : 0;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        edges.push_back({c == 0 ? 1 : 0, {a, b}});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

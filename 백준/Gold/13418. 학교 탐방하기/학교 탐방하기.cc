#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int N, M;
int entCost;
vector<pair<int, int>> edges_down, edges_up;
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
    
    for(auto curr : edges_up){
        if(cnt >= N - 1) break;
        if(makeUnion(curr.first, curr.second)){
            ++cost;
            ++cnt;
        }
    }
    
    return cost * cost;
}

long long getBest(){
    long long cost = entCost;
    int cnt = 0;
    
    makeSet();
    
    for(auto curr : edges_down){
        if(cnt >= N - 1) break;
        if(makeUnion(curr.first, curr.second)){
            ++cnt;
        }
    }
    for(auto curr : edges_up){
        if(cnt >= N - 1) break;
        if(makeUnion(curr.first, curr.second)){
            ++cost;
            ++cnt;
        }
    }
    
    return cost * cost;
}

void solve(){
    ans = getWorst() - getBest();
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    int a, b, c;
    cin >> a >> b >> c;
    entCost = !c;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        if(c) edges_down.push_back({a, b});
        else edges_up.push_back({a, b});
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

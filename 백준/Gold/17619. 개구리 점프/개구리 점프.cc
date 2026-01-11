#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

struct wood{
    int id;
    int x1, x2, y;
};

bool cmp(wood &a, wood &b){
    if(a.x1 != b.x1) return a.x1 < b.x1;
    return a.x2 < b.x2;
}

int N, Q;
vector<wood> v;
int parent[MAX_N + 1];

void makeSet(){
    for(int i=1; i<=N; i++) parent[i] = i;
    return;
}
int findRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]);
}
void makeUnion(int a, int b){
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rootA == rootB) return;
    parent[rootA] = rootB;
    return;
}
bool isUnion(int a, int b){
    return findRoot(a) == findRoot(b);
}

void solve(){
    sort(v.begin(), v.end(), cmp);
    makeSet();
    
    for(int i=0; i<N - 1; i++){
        if(v[i].x2 >= v[i + 1].x1) makeUnion(v[i].id, v[i + 1].id);
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> Q;
    
    int x1, x2, y;
    for(int i=1; i<=N; i++){
        cin >> x1 >> x2 >> y;
        v.push_back({i, x1, x2, y});
    }
    
    solve();
    
    int a, b;
    for(int q=0; q<Q; q++){
        cin >> a >> b;
        cout << (isUnion(a, b) ? 1 : 0) << '\n';
    }
    
    return 0;
}

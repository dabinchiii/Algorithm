#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

struct wood{
    int id, x1, x2;
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

void solve(){
    sort(v.begin(), v.end(), cmp);
    makeSet();
    
    int e = -1, eid = -1;
    for(int i=0; i<N; i++){
        if(v[i].x1 <= e){ // 계속 연결됨
            makeUnion(v[i].id, eid);
            e = max(e, v[i].x2);
        }
        else{ // 끊김
            eid = v[i].id;
            e = v[i].x2;
        }
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
        v.push_back({i, x1, x2});
    }
    
    solve();
    
    int a, b;
    for(int q=0; q<Q; q++){
        cin >> a >> b;
        cout << (findRoot(a) == findRoot(b) ? 1 : 0) << '\n';
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>

#define MAX_N 1000

using namespace std;

int N, M;
int parent[MAX_N + 1];
vector<int> enemy[MAX_N + 1];

int findRoot(int x){
    if(parent[x] == x) return parent[x];
    return parent[x] = findRoot(parent[x]);
}
void makeUnion(int a, int b){
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rootA != rootB) parent[rootA] = rootB;
    
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++) parent[i] = i;
    
    vector<pair<int, int>> eq;
    
    char r;
    int a, b;
    for(int i=0; i<M; i++){
        cin >> r >> a >> b;
        if(r == 'F') makeUnion(a, b);
        else{
            enemy[a].push_back(b);
            enemy[b].push_back(a);
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int e : enemy[i]){
            for(int ee : enemy[e]){
                makeUnion(i, ee);
            }
        }
    }
    
    unordered_set<int> s;
    for(int i=1; i<=N; i++) s.insert(findRoot(i));
    
    cout << s.size();
    
    return 0;
}

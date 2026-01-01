#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

#define MAX_N 1000

using namespace std;

struct loc{
    int x, y;
};

int N, M;
loc locs[MAX_N + 1];
vector<pair<double, pair<int, int>>> edges;
int parent[MAX_N + 1];
double ans;

// 이미 연결되어 있는 노드들이 주어지고,
// 아직 연결되지 않는 노드들을 최소 비용으로 연결 시켜야 한다.
// => 최소 스패닝 트리.
// 근데 엣지의 weight가 주어지지 않고 내가 구해야 함..

double getDistance(loc a, loc b){
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void makeSet(){
    for(int i=1; i<=N; i++) parent[i] = i;
    return;
}
int findRoot(int x){
    if(parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]); // 경로 압축
}
bool makeUnion(int a, int b){
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    
    if(rootA == rootB) return false; // 이미 같은 집합
    
    parent[rootB] = rootA;
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        cin >> locs[i].x >> locs[i].y;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=i + 1; j<=N; j++){
            double dist = getDistance(locs[i], locs[j]);
            edges.push_back({dist, {i, j}});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    makeSet();
    
    int cnt = 0;
    
    int u, v;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        if(makeUnion(u, v)){
            ++cnt;
        }
    }
    
    for(auto curr : edges){
        if(cnt >= N - 1) break;
        
        u = curr.second.first;
        v = curr.second.second;
        if(makeUnion(u, v)){
            ans += curr.first;
            ++cnt;
        }
    }
    
    cout << fixed << setprecision(2);
    cout << ans;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 200

using namespace std;

struct node {
    int w, u, v;
};
bool cmp(const node &a, const node &b){
    return a.w < b.w;
}

int N;
int parent[MAX_N + 1];
vector<node> edges;
int cnt;
int ansCost;
vector<pair<int, int>> ansPairs;

void makeSet() {
    for (int i = 1; i <= N; i++) parent[i] = i;
}
int findRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]);
}
bool makeUnion(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);

    if (rootA == rootB) return false;

    parent[rootA] = rootB;

    return true;
}

void solve() {
    // 이미 설치된 도로(음수 가중치)는 바로 포함 => 입력 받을 때 이미 해결함.
    // 아직 설치 여부 미정인 도로는, 사이클 만들지 않는 경우에만 포함
    
    sort(edges.begin(), edges.end(), cmp);
    
    for(auto &curr : edges){
        if(cnt >= N - 1) break;
        
        if(makeUnion(curr.u, curr.v)){
            ansCost += curr.w;
            ansPairs.push_back({curr.u, curr.v});
        }
    }


    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    makeSet();

    int w;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> w;

            if(i < j) continue;
            
            if (w < 0) {
                ansCost -= w;
                if(makeUnion(i, j)) ++cnt;
            }
            else {
                edges.push_back({w, i, j});
            }
        }
    }

    solve();
    
    cout << ansCost << ' ' << ansPairs.size() << '\n';
    for(auto &curr : ansPairs){
        cout << curr.first << ' ' << curr.second << '\n';
    }

    return 0;
}

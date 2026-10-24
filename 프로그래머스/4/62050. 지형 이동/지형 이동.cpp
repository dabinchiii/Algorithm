#include <bits/stdc++.h>

#define MAX_V 90000

using namespace std;

struct Edge{
    int u, v, cost;
};

int N;
int parent[MAX_V];

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
int solution(vector<vector<int>> land, int height) {
    N = land.size();
    for(int i=0; i<N*N; i++) parent[i] = i;
    
    vector<Edge> edges;
    int idx, diff;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            idx = i * N + j;
            
            if(i + 1 < N){
                diff = abs(land[i][j] - land[i + 1][j]);
                edges.push_back({idx, idx + N, diff <= height ? 0 : diff});
            }
            
            if(j + 1 < N){
                diff = abs(land[i][j] - land[i][j + 1]);
                edges.push_back({idx, idx + 1, diff <= height ? 0 : diff});
            }
        }
    }
    
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){
        return a.cost < b.cost;
    });
    
    int ans = 0;
    for(Edge &curr : edges){
        if(makeUnion(curr.u, curr.v)) ans += curr.cost;
    }
    
    return ans;
}
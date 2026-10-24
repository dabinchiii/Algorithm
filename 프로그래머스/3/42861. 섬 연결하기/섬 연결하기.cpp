#include <bits/stdc++.h>

#define MAX_N 100

using namespace std;

int parent[MAX_N];

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

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    });
    
    for(int i=0; i<n; i++) parent[i] = i;
    
    int ans = 0;
    for(vector<int> &curr : costs){
        if(makeUnion(curr[0], curr[1])) ans += curr[2];
    }
    
    return ans;
}
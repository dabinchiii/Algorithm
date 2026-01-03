#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 1024

using namespace std;

struct node{
    int dist, u, v;
};

bool cmp(node &a, node &b){
    return a.dist < b.dist;
}

int N;
int sd[MAX_N + 1][MAX_N + 1]; // 최단거리
int adj[MAX_N + 1][MAX_N + 1];
vector<node> v;

void solve(){
    sort(v.begin(), v.end(), cmp);
    
    for(auto curr : v){
        
        bool flag = false;
        for(int i=1; i<=N; i++){
            if(adj[curr.u][i] > 0 && adj[curr.u][i] + sd[i][curr.v] == curr.dist){
                flag = true;
                break;
            }
        }
        
        if(flag) continue;
        
        adj[curr.u][curr.v] = adj[curr.v][curr.u] = curr.dist;
    }
    
    queue<int> q;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(adj[i][j]) q.push(j);
        }
        cout << q.size() << ' ';
        while(!q.empty()){
            cout << q.front() << ' ';
            q.pop();
        }
        cout << '\n';
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    int dist;
    for(int i=1; i<=N; i++){
        for(int j=i + 1; j<=N; j++){
            cin >> dist;
            sd[i][j] = sd[j][i] = dist;
            v.push_back({dist, i, j});
        }
    }
    
    solve();
    
    
    return 0;
}

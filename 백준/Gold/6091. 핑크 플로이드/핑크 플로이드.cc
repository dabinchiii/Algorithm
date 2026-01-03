#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define MAX_N 1024

using namespace std;

struct node{
    int dist, u, v;
};

bool cmp(const node &a, const node &b){
    return a.dist < b.dist;
}

int N;
int sd[MAX_N + 1][MAX_N + 1]; // 최단거리
vector<pair<int, int>> adj[MAX_N + 1];
vector<node> v;

void solve(){
    sort(v.begin(), v.end(), cmp);
    
    for(auto &curr : v){
        bool flag = false;
        for(auto &nxt : adj[curr.u]){
            if(nxt.second + sd[nxt.first][curr.v] == curr.dist){
                flag = true;
                break;
            }
        }
        
        if(flag) continue;
        
        adj[curr.u].push_back({curr.v, curr.dist});
        adj[curr.v].push_back({curr.u, curr.dist});
    }
    
    ostringstream out;
    for(int i=1; i<=N; i++){
        out << adj[i].size() << ' ';
        sort(adj[i].begin(), adj[i].end());
        for(auto nxt : adj[i]) out << nxt.first << ' ';
        out << '\n';
    }
    
    cout << out.str();
    
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

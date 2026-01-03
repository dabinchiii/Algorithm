#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 50

using namespace std;

int N;
vector<pair<int, int>> g[MAX_N];
int total, ans;

void solve(){
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(N, false);
    int cnt = 0, cost = 0;
    
    pq.push({0, 0});
    
    while(!pq.empty() && cnt < N){
        int currW = -pq.top().first;
        int currV = pq.top().second;
        pq.pop();
        
        if(visited[currV]) continue;
        
        visited[currV] = true;
        cost += currW;
        ++cnt;
        
        for(auto nxt : g[currV]){
            if(!visited[nxt.first]) pq.push({-nxt.second, nxt.first});
        }
    }
    
    if(cnt < N){
        ans = -1;
        return;
    }
    
    ans = total - cost;
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    string line;
    char ch;
    int len;
    for(int i=0; i<N; i++){
        cin >> line;
        for(int j=0; j<N; j++){
            ch = line[j];
            
            if(ch == '0') continue;
            else if(ch >= 'a' && ch <= 'z') len = (ch - 'a') + 1;
            else len = (ch - 'A') + 27;
            
            g[i].push_back({j, len});
            g[j].push_back({i, len});
            total += len;
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

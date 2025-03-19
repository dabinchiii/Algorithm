#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int c[30001];
vector<int> g[30001];
int ans;

int cntCandy[30001], w[30001];
bool visited[30001];

void bfs(int start){
    if(visited[start]) return;
    
    queue<int> q;
    q.push(start);
    
    visited[start] = true;
    cntCandy[start] = c[start];
    
    int cntCry = 1;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int nxt : g[curr]){
            if(visited[nxt]) continue;
            
            q.push(nxt);
            visited[nxt] = true;
            cntCandy[start] += c[nxt];
            cntCry++;
        }
    }
    
    w[start] = cntCry;
    if(cntCry >= k) cntCandy[start] = -1;
    
    return;
}

int knapsack(vector<pair<int, int>> v){
    int len = (int)v.size();
    vector<vector<int>> dp(len + 1, vector<int>(k, 0));
    
    for(int i=1; i<=len; i++){
        int currW = v[i - 1].first;
        int currV = v[i - 1].second;
        
        for(int j=1; j<k; j++){
            if(currW > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], currV + dp[i - 1][j - currW]);
        }
    }

    return dp[len][k - 1];
}

void solve(){
    for(int i=1; i<=n; i++){
        bfs(i);
    }

    for(int i=1; i<=n; i++){
        ans = max(ans, cntCandy[i]);
    }
    
    vector<pair<int, int>> v;
    for(int i=1; i<=n; i++){
        if(cntCandy[i] == 0) continue;
        v.push_back({w[i], cntCandy[i]});
    }
    
    sort(v.begin(), v.end());

    ans = knapsack(v);
    
    return;
}

int main(){
    cin >> n >> m >> k;
    
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
    
    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

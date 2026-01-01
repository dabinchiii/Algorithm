#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 1000

using namespace std;

int N;
int w[MAX_N][MAX_N];
long long ans;

void solve(){
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(N, false);
    int cnt = 0;
    
    pq.push({0, 0});
    
    while(!pq.empty() && cnt < N){
        int currW = -pq.top().first;
        int currV = pq.top().second;
        pq.pop();
        
        if(visited[currV]) continue;
        
        visited[currV] = true;
        ++cnt;
        ans += currW;
        
        for(int i=0; i<N; i++){
            if(visited[i]) continue;
            pq.push({-w[currV][i], i});
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> w[i][j];
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

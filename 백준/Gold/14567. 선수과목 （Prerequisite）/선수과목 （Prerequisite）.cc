#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1000

using namespace std;

int N, M;
vector<int> g[MAX_N + 1];
int inDegree[MAX_N + 1];

int ans[MAX_N + 1];

void solve(){
    queue<int> q;
    
    for(int i=1; i<=N; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    
    int round = 0;
    while(!q.empty()){
        int cnt = (int)q.size();
        
        round++;
        for(int i=0; i<cnt; i++){
            int curr = q.front();
            q.pop();
            
            ans[curr] = round;
            for(int nxt : g[curr]){
                if(--inDegree[nxt] == 0) q.push(nxt);
            }
        }
    }
    
    return;
}

int main(){
    cin >> N >> M;
    
    int A, B;
    for(int i=0; i<M; i++){
        cin >> A >> B;
        g[A].push_back(B);
        inDegree[B]++;
    }
    
    solve();
    
    for(int i=1; i<=N; i++){
        cout << ans[i] << ' ';
    }
    
    return 0;
}



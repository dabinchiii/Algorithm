#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1000

using namespace std;

int N, M;
vector<int> g[MAX_N + 1];
int inDegree[MAX_N + 1];

vector<int> ans;

void solve(){
    queue<int> q;
    
    for(int i=1; i<=N; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        ans.push_back(curr);
        
        for(int nxt : g[curr]){
            if(--inDegree[nxt] == 0) q.push(nxt);
        }
    }
    
    return;
}

int main(){
    cin >> N >> M;
    
    int cnt, prev, curr;
    for(int i=0; i<M; i++){
        cin >> cnt >> prev;
        
        for(int j=1; j<cnt; j++){
            cin >> curr;
            
            g[prev].push_back(curr);
            inDegree[curr]++;
            
            prev = curr;
        }
    }
    
    solve();
    
    if(ans.size() == N){
        for(int curr : ans){
            cout << curr << '\n';
        }
    }
    else{
        cout << 0;
    }
    
    
    return 0;
}



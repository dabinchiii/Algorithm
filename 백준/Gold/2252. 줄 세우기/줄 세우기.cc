#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 32000

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
    
    int A, B;
    for(int i=0; i<M; i++){
        cin >> A >> B;
        g[A].push_back(B);
        inDegree[B]++;
    }
    
    solve();
    
    for(int curr : ans){
        cout << curr << ' ';
    }
    
    return 0;
}



#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 50
#define MAX_M 50

using namespace std;

int N, M;
bool g[MAX_N + 1][MAX_N + 1];
vector<int> party[MAX_N];
bool w[MAX_N + 1];
int ans;

void solve(){
    queue<int> q;
    
    for(int i=1; i<=N; i++){
        if(w[i]) q.push(i);
    }
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int i=1; i<=N; i++){
            if(!g[curr][i] || w[i]) continue;
            
            w[i] = true;
            q.push(i);
        }
    }
    
    for(int i=0; i<M; i++){
        bool flag = true;
        for(int curr : party[i]){
            if(w[curr]){
                flag = false;
                break;
            }
        }
        if(flag) ++ans;
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    int cntw, no;
    cin >> cntw;
    for(int i=0; i<cntw; i++){
        cin >> no;
        w[no] = true;
    }
    
    int cntp;
    for(int i=0; i<M; i++){
        cin >> cntp;
        for(int j=0; j<cntp; j++){
            cin >> no;
            party[i].push_back(no);
            
            for(int k=0; k<j; k++){
                g[no][party[i][k]] = g[party[i][k]][no] = true;
            }
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

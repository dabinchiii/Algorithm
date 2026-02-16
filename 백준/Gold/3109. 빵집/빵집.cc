#include <iostream>
#include <stack>

#define MAX_R 10000
#define MAX_C 500

#define WALL MAX_R + 1

using namespace std;

struct loc{
    int r, c;
};

int dr[] = {1, 0, -1};

int R, C;
int visited[MAX_R][MAX_C];
bool arrived[MAX_R + 2];
int ans;

void print(){
    cout << "\n===================\n";
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(visited[i][j] == WALL) cout << 'x' << ' ';
            else cout << visited[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}
void go(int id, int r, int c){
    stack<loc> st;
    st.push({r, c});
    
    while(!st.empty()){
        loc curr = st.top(); st.pop();
        
        visited[curr.r][curr.c] = id;
        
        if(curr.c == C - 1){
            arrived[id] = true;
            ++ans;
            break;
        }
        
        for(int d=0; d<3; d++){
            int nr = curr.r + dr[d];
            int nc = curr.c + 1;
            
            if(nr < 0 || nr >= R) continue;
            if(visited[nr][nc] == id || arrived[visited[nr][nc]]) continue;
            
            st.push({nr, nc});
        }
    }
    
    return;
}
void solve(){
    for(int i=0; i<R; i++) go(i + 1, i, 0);
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    arrived[WALL] = true;
    
    cin >> R >> C;
    
    string line;
    for(int i=0; i<R; i++){
        cin >> line;
        for(int j=0; j<C; j++){
            if(line[j] == 'x') visited[i][j] = WALL;
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

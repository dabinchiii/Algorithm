#include <iostream>
#include <queue>

using namespace std;

typedef struct qNode{
    int x, y;
    int cntBroke;
    int dist;
}qNode;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, k;
bool isWall[1001][1001];
int ans;

bool visited[1001][1001][10];

void solve(){
    queue<qNode> q;
    
    q.push({1, 1, 0, 1});
    visited[1][1][0] = true;
    
    while(!q.empty()){
        qNode curr = q.front();
        q.pop();
        
        if(curr.x == n && curr.y == m){
            ans = curr.dist;
            return;
        }
        
        for(int i=0; i<4; i++){
            int nxtX = curr.x + dx[i];
            int nxtY = curr.y + dy[i];
            
            if(nxtX < 1 || nxtX > n || nxtY < 1 || nxtY > m) continue;
            
            if(isWall[nxtX][nxtY]){ // 벽
                if(curr.cntBroke >= k || visited[nxtX][nxtY][curr.cntBroke + 1]) continue;
                
                visited[nxtX][nxtY][curr.cntBroke + 1] = true;
                q.push({nxtX, nxtY, curr.cntBroke + 1, curr.dist + 1});
            }
            else{ // 벽 아님
                if(visited[nxtX][nxtY][curr.cntBroke]) continue;
                
                visited[nxtX][nxtY][curr.cntBroke] = true;
                q.push({nxtX, nxtY, curr.cntBroke, curr.dist + 1});
            }
        }
        
    }
    
    ans = -1;
    
    return;
}

int main(){
    cin >> n >> m >> k;
    
    string str;
    for(int i=1; i<=n; i++){
        cin >> str;
        for(int j=1; j<=m; j++){
            isWall[i][j] = (str[j - 1] == '1' ? true : false);
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}

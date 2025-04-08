
#include <bits/stdc++.h>
using namespace std;

typedef struct pos{
    int y, x;
}pos;
typedef struct node{
    pos p; // 위치 (y, x)
    bool broken; // 0: 아직 벽 안 부숨, 1: 이미 벽 부숨
    int dst; // (0, 0)부터의 거리
}node;

int n, m, ans;
bool arr[1000][1000];
bool visited[1000][1000][2]; // [][][0] : 아직 벽 안 부쉈다. [][][1] : 이미 벽 하나 부쉈다.
queue<node> q;

pos dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

pos operator+(pos& a, pos& b){
    return {a.y+b.y, a.x+b.x};
}

void bfs(){
    while(!q.empty()){
        node current = q.front();
        q.pop();

        if(current.p.y==n-1 && current.p.x==m-1)
            ans = min(ans, current.dst);


        for(int i=0; i<4; ++i){
            node next;
            next.p = current.p + dir[i];

            if(next.p.y<0 || next.p.y>=n) continue;
            if(next.p.x<0 || next.p.x>=m) continue;

            if(arr[next.p.y][next.p.x] && !current.broken){ // 벽이고, 벽 부술 수 있음
                visited[next.p.y][next.p.x][1] = true;
                next.broken = true; // 부쉈다
                next.dst = current.dst + 1;
                q.push(next);
            }
            if(!arr[next.p.y][next.p.x] && !visited[next.p.y][next.p.x][current.broken]){ // 벽 아니고, 방문 안했음
                visited[next.p.y][next.p.x][current.broken] = true;
                next.broken = current.broken;
                next.dst = current.dst + 1;
                q.push(next);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    string str;
    for(int i=0; i<n; ++i){
        cin >> str;
        for(int j=0; j<m; ++j){
            arr[i][j] = str[j]=='1'?true:false;
        }
    }

    ans = n*m+1;

    visited[0][0][0] = true;
    q.push({{0, 0}, false, 1});

    bfs();

    if(ans == n*m+1) ans = -1;

    cout << ans;

    return 0;
}

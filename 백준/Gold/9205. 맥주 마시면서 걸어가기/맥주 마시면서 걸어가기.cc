#include <bits/stdc++.h>
#define MAX_N 100

using namespace std;

struct pos{
    int x, y;
};

int n;
struct pos home, festival;
struct pos conv[MAX_N + 2];
int dis[MAX_N][MAX_N];
bool visited[MAX_N];
bool isHappy;

void init(){
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    isHappy = false;
}

void solve(){
    for(int i=0; i<n + 2; i++){
        for(int j=0; j<n + 2; j++){
            dis[i][j] = abs(conv[i].x - conv[j].x) + abs(conv[i].y - conv[j].y);
        }
    }

    queue<int> q;
    q.push(n + 1); // 인덱스를 저장
    visited[n + 1] = true;

    while(!q.empty()){
        int currIdx = q.front();
        q.pop();

        if(currIdx == 0){
            isHappy = true;
            break;
        }

        for(int i=0; i<=n; i++){
            if(dis[currIdx][i] <= 1000 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;

        cin >> home.x >> home.y;
        for(int i=1; i<=n; i++){
            cin >> conv[i].x >> conv[i].y;
        }
        cin >> festival.x >> festival.y;

        conv[0] = home;
        conv[n+1] = festival;

        init();
        solve();

        cout << (isHappy ? "happy" : "sad") << '\n';
    }

    return 0;
}

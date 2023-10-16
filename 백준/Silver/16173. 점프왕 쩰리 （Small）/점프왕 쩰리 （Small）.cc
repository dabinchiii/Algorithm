#include <bits/stdc++.h>
using namespace std;

int n;
int area[64][64];
bool visited[64][64];
bool Answer;

void dfs(int x, int y){
    if(area[x][y] == -1){
        Answer = true;
        return;
    }

    visited[x][y] = true;
    int curr = area[x][y];
    if(curr == 0) return;

    if(x + curr < n && !visited[x + curr][y])
        dfs(x + curr, y);
    if(y + curr < n && !visited[x][y + curr])
        dfs(x, y + curr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> area[i][j];
        }
    }

    dfs(0, 0); // ½ÃÀÛÁ¡

    cout << (Answer ? "HaruHaru" : "Hing");

    return 0;
}

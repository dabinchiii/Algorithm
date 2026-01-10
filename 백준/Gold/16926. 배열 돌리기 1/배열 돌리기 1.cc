#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 300
#define MAX_M 300

using namespace std;

int N, M, R;
int board[MAX_N][MAX_M];

void rotateLayer(int l){
    vector<int> v;
    
    for(int c=l; c<M - l - 1; c++) v.push_back(board[l][c]);
    for(int r=l; r<N - l - 1; r++) v.push_back(board[r][M - l - 1]);
    for(int c=M - l - 1; c>l; c--) v.push_back(board[N - l - 1][c]);
    for(int r=N - l - 1; r>l; r--) v.push_back(board[r][l]);
    
    int len = (int)v.size();
    int k = R % len;
    
    rotate(v.begin(), v.begin() + k, v.end());
    
    int idx = 0;
    for(int c=l; c<M - l - 1; c++) board[l][c] = v[idx++];
    for(int r=l; r<N - l - 1; r++) board[r][M - l - 1] = v[idx++];
    for(int c=M - l - 1; c>l; c--) board[N - l - 1][c] = v[idx++];
    for(int r=N - l - 1; r>l; r--) board[r][l] = v[idx++];
    
    return;
}

void solve(){
    int cnt = min(N, M) / 2;
    for(int i=0; i<cnt; i++) rotateLayer(i);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    
    solve();
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}

#include <bits/stdc++.h>

#define MAX 100

using namespace std;

bool board[MAX + 1][MAX + 1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2;
    for(int r=0; r<4; r++){
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i=y1; i<y2; i++){
            for(int j=x1; j<x2; j++){
                board[i][j] = true;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=MAX; i++){
        for(int j=0; j<=MAX; j++){
            ans += board[i][j];
        }
    }

    cout << ans;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    // accW : 왼쪽 위 모서리가 W일 경우, 틀린(새로 칠해야하는) 개수의 누적합
    //        행,열 번호가 모두 짝수이거나 홀수일 때 W. 아니면 B.
    vector<vector<int>> accW(n+1, vector<int>(m+1, 0));
    vector<vector<int>> accB(n+1, vector<int>(m+1, 0));

    char color;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> color;

            // 틀린 경우를 카운트
            if((i + j) % 2 == 0){
                // 행열이 모두 짝수이거나 홀수인 경우 (짝짝, 홀홀)
                if(color == 'W') accB[i][j]++;
                else if(color == 'B') accW[i][j]++;
            }
            else{
                // (짝홀, 홀짝)
                if(color == 'W') accW[i][j]++;
                else if(color == 'B') accB[i][j]++;
            }

            accW[i][j] += accW[i-1][j];
            accW[i][j] += accW[i][j-1];
            accW[i][j] -= accW[i-1][j-1];

            accB[i][j] += accB[i-1][j];
            accB[i][j] += accB[i][j-1];
            accB[i][j] -= accB[i-1][j-1];
        }
    }

    int Answer = 40000001;
    for(int i=0; i<=n-k; i++){
        for(int j=0; j<=m-k; j++){
            int x, y;
            x = i + k;
            y = j + k;

            int sumW = accW[x][y];
            sumW -= accW[x][j];
            sumW -= accW[i][y];
            sumW += accW[i][j];
            Answer = min(Answer, sumW);

            int sumB = accB[x][y];
            sumB -= accB[x][j];
            sumB -= accB[i][y];
            sumB += accB[i][j];
            Answer = min(Answer, sumB);
        }
    }
    cout << Answer;

    return 0;
}

#include <vector>

#define MAX_N 100

using namespace std;

bool r[MAX_N + 1][MAX_N + 1]; // [a][b]가 true다 => a가 b를 이긴다

int solution(int n, vector<vector<int>> results) {
    
    for(vector<int> curr : results){
        r[curr[0]][curr[1]] = true;
    }
    
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(r[i][k] && r[k][j]) r[i][j] = true;
            }
        }
    }
    
    int ans = 0;
    for(int i=1; i<=n; ++i){
        int cnt = 0; // 나(i번 선수)보다 확실히 작거나 큰 선수의 수
        for(int j=1; j<=n; ++j){
            if(r[i][j] || r[j][i]) ++cnt;
        }
        if(cnt == n - 1) ++ans;
    }
    
    return ans;
}
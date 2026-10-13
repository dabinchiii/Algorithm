#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

int N;
int dp1[2][MAX_N + 1], dp2[2][MAX_N + 1]; 
// dp1: 첫 원소를 쓸 수 없는 경우, dp2는 쓸 수 있는 경우

int solution(vector<int> sticker)
{
    N = sticker.size();
    
    if(N == 1) return sticker[0];
    
    dp1[0][1] = dp1[1][1] = 0;
    dp2[0][1] = sticker[0];
    dp2[1][1] = 0;
    for(int i=2; i<=N; i++){
        dp1[0][i] = sticker[i - 1] + max(dp1[0][i - 2], dp1[1][i - 1]);
        dp1[1][i] = max(dp1[0][i - 1], dp1[1][i - 1]);
        
        dp2[0][i] = sticker[i - 1] + max(dp2[0][i - 2], dp2[1][i - 1]);
        dp2[1][i] = max(dp2[0][i - 1], dp2[1][i - 1]);
    }
    
//     for(int i=1; i<=N; i++){
//         cout << dp1[0][i] << '\t';
//     }
//     cout << endl;
//     for(int i=1; i<=N; i++){
//         cout << dp1[1][i] << '\t';
//     }
//     cout << "\n===================\n";
//     for(int i=1; i<=N; i++){
//         cout << dp2[0][i] << '\t';
//     }
//     cout << endl;
//     for(int i=1; i<=N; i++){
//         cout << dp2[1][i] << '\t';
//     }
    
    return max(max(dp1[0][N], dp1[1][N]), dp2[1][N]);
}
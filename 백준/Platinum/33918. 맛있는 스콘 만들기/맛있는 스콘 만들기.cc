#include <iostream>
#include <deque>
#include <cmath>

#define MAX_N 200
#define MAX_M 25000

using namespace std;

int N, M, C, D;
int bt[MAX_N];
int dp[MAX_N][MAX_M + 1];
int ans;

void solve(){
    for(int i=0; i<N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] = M - abs(bt[i] - j);
        }
    }
    
    for(int i=1; i<N; i++){
        for(int j=1; j<=C; j++){
            deque<pair<int, int>> dq;
            
            for(int idx=j; idx < j + D; idx += C){
                int value = dp[i - 1][idx];
                while(!dq.empty() && dq.back().second <= value) dq.pop_back();
                dq.push_back({idx, value});
            }
            
            for(int curr=j; curr <= M; curr += C){
                if(curr + D <= M){
                    int value = dp[i - 1][curr + D];
                    while(!dq.empty() && dq.back().second <= value) dq.pop_back();
                    dq.push_back({curr + D, value});
                }
                
                while(!dq.empty() && (curr - dq.front().first) > D) dq.pop_front();
                dp[i][curr] += dq.front().second;
            }
            
            
        }
    }
    
    for(int i=1; i<=M; i++) ans = max(ans, dp[N - 1][i]);
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> C >> D;
    for(int i=0; i<N; i++) cin >> bt[i];
    solve();
    cout << ans;
    
    return 0;
}

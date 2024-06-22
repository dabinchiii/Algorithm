#include <bits/stdc++.h>
#define MAX_C 100000

using namespace std;

vector<int> comm;
int cost[5][5];
int dp[5][5][MAX_C];
int ans = 400000;

int getCost(int from, int to){
    if(from == to) return 1;
    if(from == 0) return 2;
    if(from % 2 != to % 2) return 3;
    return 4;
}

int solve(int left, int right, int idx){
    if(idx == comm.size()) return 0;

    if(dp[left][right][idx] == -1){
        int moveLeft = solve(comm[idx], right, idx + 1) + getCost(left, comm[idx]);
        int moveRight = solve(left, comm[idx],idx + 1) + getCost(right, comm[idx]);
        dp[left][right][idx] = min(moveLeft, moveRight);
    }

    return dp[left][right][idx];
}

void init(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<MAX_C; k++){
                dp[i][j][k] = -1;
            }
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    while(true){
        cin >> c;
        if(c == 0) break;
        comm.push_back(c);
    }

    init();

    ans = solve(0, 0, 0);
    cout << ans;

    return 0;
}

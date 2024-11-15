#include <iostream>

using namespace std;

int n, k;
int board[17][17];
int ans;

void solve(){
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }

    ans = 0;

    // 가로 체크
    for(int i=1; i<=n; i++){
        int currLen = 0;
        for(int j=1; j<=n + 1; j++){
            if(board[i][j] == 1){
                currLen++;
            }
            else{
                if(currLen == k) ans++;
                currLen = 0;
            }
        }
    }

    // 세로 체크
    for(int i=1; i<=n; i++){
        int currLen = 0;

        for(int j=1; j<=n + 1; j++){
            if(board[j][i] == 1){
                currLen++;
            }
            else{
                if(currLen == k) ans++;
                currLen = 0;
            }
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;  
    cin >> T;

    for(int t=1; t<=T; t++){
        solve();
        cout << '#' << t << ' ' << ans << '\n';
    }

    return 0;
}
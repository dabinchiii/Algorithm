#include <iostream>

using namespace std;

int n;
int board[7][7];
int r90[7][7], r180[7][7], r270[7][7];

void solve(){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            r90[i][j] = board[n - j - 1][i];
            r180[i][j] = board[n - i - 1][n - j - 1];
            r270[i][j] = board[j][n - i - 1];
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << r90[i][j];
        }
        cout << ' ';

        for(int j=0; j<n; j++){
            cout << r180[i][j];
        }
        cout << ' ';

        for(int j=0; j<n; j++){
            cout << r270[i][j];
        }
        cout << '\n';
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;  
    cin >> T;

    for(int t=1; t<=T; t++){
        cout << '#' << t << ' ' << '\n';
        solve();
    }

    return 0;
}
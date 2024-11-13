#include <iostream>

using namespace std;

int n;
int board[10][12];

void makePascalTriangle(){
    board[0][1] = 1;
    
    for(int i=1; i<10; i++){
        for(int j=1; j<=i + 1; j++){
            board[i][j] = board[i - 1][j - 1] + board[i - 1][j];
        }
    }

    return;
}

void solve(){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << board[i][j + 1] << ' ';
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

    makePascalTriangle();

    for(int t=1; t<=T; t++){
        cout << "#" << t << '\n';
        solve();
    }

    return 0;
}
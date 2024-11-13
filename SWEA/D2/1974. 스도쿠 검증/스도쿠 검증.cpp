#include <iostream>
#include <set>

using namespace std;

int board[9][9];
bool ans;

void solve(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> board[i][j];
        }
    }

    set<int> numRow[9], numCol[9], numBox[3][3];

    int curr;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            curr = board[i][j];

            numRow[i].insert(curr);
            numCol[j].insert(curr);
            numBox[i / 3][j / 3].insert(curr);
        }
    }

    ans = true;
    
    for(int i=0; i<9; i++){
        if(numRow[i].size() == 9 && numCol[i].size() == 9) continue;

        ans = false;
        return; 
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(numBox[i][j].size() == 9) continue;

            ans = false;
            return;
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
        cout << "#" << t << ' ' << (ans ? 1 : 0) << '\n';
    }

    return 0;
}
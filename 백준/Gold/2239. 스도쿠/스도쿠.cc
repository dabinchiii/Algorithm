#include <bits/stdc++.h>

using namespace std;

int board[9][9], ans[9][9];
bool row[9][10], col[9][10], box[3][3][10];

pair<int, int> findNextBlank(int x, int y){
    int currX = x, currY = y;

    while(board[currX][currY] != 0){
        currY++;
        if(currY == 9){
            currY = 0;
            currX++;
        }
        if(currX == 9){
            return {-1, -1};
        }
    }

    return {currX, currY};
}

void bt(int x, int y){
    if(ans[0][0] != 0) return;
    if(x == -1){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                ans[i][j] = board[i][j];
            }
        }

        return;
    }

    board[x][y] = -1;
    pair<int, int> nxt = findNextBlank(x, y);
    board[x][y] = 0;

    for(int i=1; i<=9; i++){
        if(row[x][i]) continue;
        if(col[y][i]) continue;
        if(box[x/3][y/3][i]) continue;

        board[x][y] = i;
        row[x][i] = col[y][i] = box[x/3][y/3][i] = true;

        bt(nxt.first, nxt.second);

        board[x][y] = 0;
        row[x][i] = col[y][i] = box[x/3][y/3][i] = false;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int num;
    for(int i=0; i<9; i++){
        cin >> str;
        for(int j=0; j<9; j++){
            num = str[j] - '0';
            board[i][j] = num;

            row[i][num] = true;
            col[j][num] = true;
            box[i/3][j/3][num] = true;
        }
    }

    pair<int, int> start = findNextBlank(0, 0);
    bt(start.first, start.second);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}

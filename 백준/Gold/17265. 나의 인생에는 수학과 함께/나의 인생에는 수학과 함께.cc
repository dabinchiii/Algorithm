#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> board(5, vector<char>(5));
int AnswerMax = -99999999, AnswerMin = 99999999;

void dfs(int x, int y, int currValue, char currOper, int cnt){
    if(cnt % 2 == 0){ // 숫자
        if(currOper == '+'){
            currValue += board[x][y] - '0';
        }
        else if(currOper == '-'){
            currValue -= board[x][y] - '0';
        }
        else{
            currValue *= board[x][y] - '0';
        }
    }
    else{
        currOper = board[x][y];
    }

    if(x == n-1 && y == n-1){
        AnswerMax = max(AnswerMax, currValue);
        AnswerMin = min(AnswerMin, currValue);
        return;
    }

    if(x + 1 < n){
        dfs(x + 1, y, currValue, currOper, cnt + 1);
    }
    if(y + 1 < n) {
        dfs(x, y + 1, currValue, currOper, cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 0, '+', 0);

    cout << AnswerMax << ' ' << AnswerMin;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int gear[4][8], top[4];
int k;
int commNum[100], commDir[100];
int ans;

void startRotation(int num, int dir){
    int d[4] = { 0 };
    d[num] = dir;

    int currNum = num;
    while(currNum > 0){
        int currLeft = gear[currNum][(top[currNum] + 6) % 8];
        int nxtRight = gear[currNum - 1][(top[currNum - 1] + 2) % 8];

        if(currLeft == nxtRight) break;

        d[currNum - 1] = -d[currNum];
        currNum--;
    }

    currNum = num;
    while(currNum < 4){
        int currRight = gear[currNum][(top[currNum] + 2) % 8];
        int nxtLeft = gear[currNum + 1][(top[currNum + 1] + 6) % 8];

        if(currRight == nxtLeft) break;

        d[currNum + 1] = -d[currNum];
        currNum++;
    }

    for(int i=0; i<4; i++){
        top[i] = (top[i] - d[i] + 8) % 8;
    }

    return;
}

void solve(){
    for(int i=0; i<k; i++){
        startRotation(commNum[i], commDir[i]);
    }

    for(int i=0; i<4; i++){
        if(gear[i][top[i]] == 1){
            ans += pow(2, i);
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    for(int i=0; i<4; i++){
        cin >> str;
        for(int j=0; j<8; j++){
            gear[i][j] = str[j] - '0';
        }
    }

    cin >> k;
    for(int i=0; i<k; i++){
        cin >> commNum[i] >> commDir[i];
        commNum[i]--;
    }

    solve();

    cout << ans;

    return 0;
}

#include <bits/stdc++.h>
#define MAX_N 15

using namespace std;

int n, Answer;
vector<int> row(MAX_N);

bool check(int r){
    for(int i=0; i<r; i++){
        if(row[i] == row[r]) return false;
        if(abs(row[r] - row[i]) == r - i) return false;
    }
    return true;
}

void nqueen(int cnt){
    if(cnt == n){
        Answer++;
        return;
    }

    for(int i=0; i<n; i++){
        row[cnt] = i;

        if(!check(cnt)) continue;
        nqueen(cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    nqueen(0);

    cout << Answer;

    return 0;
}

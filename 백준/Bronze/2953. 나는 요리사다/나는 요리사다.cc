#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> score(6, 0);
    for(int i=1; i<=5; i++){
        int num;
        for(int j=0; j<4; j++){
            cin >> num;
            score[i] += num;
        }
    }

    int maxScore = -1, winner;
    for(int i=1; i<=5; i++){
        if(score[i] > maxScore){
            maxScore = score[i];
            winner = i;
        }
    }

    cout << winner << ' ' << maxScore;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Answer = 0;

    int score, minValue = 101;
    for(int i=0; i<4; i++){
        cin >> score;
        Answer += score;
        minValue = min(minValue, score);
    }
    Answer -= minValue;

    minValue = 101;
    for(int i=0; i<2; i++){
        cin >> score;
        Answer += score;
        minValue = min(minValue, score);
    }
    Answer -= minValue;

    cout << Answer;

    return 0;
}

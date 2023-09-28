#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int Answer = 0;
    int score, curr = 0;
    for(int i=0; i<n; i++){
        cin >> score;

        if(score == 0) curr = 0;
        else curr++;

        Answer += curr;
    }

    cout << Answer;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int Answer = 0;
    int currLeft = 0, currRight = 0;
    int dir;
    for(int i=0; i<n; i++){
        cin >> dir;

        if(dir == 1){ // left
            currLeft++;
            currRight = max(0, currRight - 1);
        }
        else{
            currRight++;
            currLeft = max(0, currLeft - 1);
        }

        Answer = max(Answer, max(currLeft, currRight));
    }

    cout << Answer;

    return 0;
}

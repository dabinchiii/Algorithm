#include <bits/stdc++.h>

using namespace std;

void solve(int classNum){
    int n;
    cin >> n;

    int maxS = -1, minS = 101;
    int score[n];
    for(int i=0; i<n; i++){
        cin >> score[i];
        maxS = max(maxS, score[i]);
        minS = min(minS, score[i]);
    }

    sort(score, score + n);

    int lgGap = -1;
    for(int i=1; i<n; i++){
        lgGap = max(lgGap, score[i] - score[i - 1]);
    }

    cout << "Class " << classNum << '\n';
    cout << "Max " << maxS << ", ";
    cout << "Min " << minS << ", ";
    cout << "Largest gap " << lgGap << '\n';

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    for(int i=1; i<=k; i++){
        solve(i);
    }

    return 0;
}

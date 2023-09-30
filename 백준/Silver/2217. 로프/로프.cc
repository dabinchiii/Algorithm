#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> rope(n);
    for(int i=0; i<n; i++){
        cin >> rope[i];
    }

    sort(rope.begin(), rope.end());

    int Answer = -1;
    int k;
    for(int i=0; i<n; i++){
        k = n - i;
        Answer = max(Answer, rope[i] * k);
    }

    cout << Answer;

    return 0;
}

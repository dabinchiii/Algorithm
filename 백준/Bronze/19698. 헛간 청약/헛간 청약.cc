#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, h, l;
    cin >> n >> w >> h >> l;

    int Answer = (w / l) * (h / l);
    Answer = min(Answer, n);

    cout << Answer;

    return 0;
}

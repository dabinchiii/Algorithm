#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> w(10), k(10);
    for(int i=0; i<10; i++){
        cin >> w[i];
    }
    for(int i=0; i<10; i++){
        cin >> k[i];
    }

    sort(w.begin(), w.end(), greater<int>());
    sort(k.begin(), k.end(), greater<int>());

    int scoreW = 0, scoreK = 0;
    for(int i=0; i<3; i++){
        scoreW += w[i];
        scoreK += k[i];
    }

    cout << scoreW << ' ' << scoreK;

    return 0;
}

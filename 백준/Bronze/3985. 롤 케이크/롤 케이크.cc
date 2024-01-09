#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, n;
    cin >> l >> n;

    vector<bool> visited(l + 1, false);
    vector<int> cntCake(n + 1, 0);
    int p, k;
    int maxEValue = -1, maxEIdx = -1;
    for(int i=1; i<=n; i++){
        cin >> p >> k;

        if(k - p + 1 > maxEValue){
            maxEValue = k - p + 1;
            maxEIdx = i;
        }

        for(int j=p; j<=k; j++){
            if(visited[j]) continue;
            visited[j] = true;
            cntCake[i]++;
        }
    }

    int maxRValue = -1, maxRIdx = -1;
    for(int i=1; i<=n; i++){
        if(cntCake[i] > maxRValue){
            maxRValue = cntCake[i];
            maxRIdx = i;
        }
    }

    cout << maxEIdx << '\n' << maxRIdx;

    return 0;
}

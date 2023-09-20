#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> bucket(n+1, 0);
    int from, to, num;
    for(int i=0; i<m; i++){
        cin >> from >> to >> num;

        for(int j=from; j<=to; j++){
            bucket[j] = num;
        }
    }

    for(int i=1; i<=n; i++){
        cout << bucket[i] << ' ';
    }

    return 0;
}

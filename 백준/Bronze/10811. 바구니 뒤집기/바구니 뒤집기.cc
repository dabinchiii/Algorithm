#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> bucket(n+1);
    for(int i=1; i<=n; i++){
        bucket[i] = i;
    }

    int from, to;
    for(int i=0; i<m; i++){
        cin >> from >> to;

        for(int j=0; j<(to-from+1)/2; j++){
            swap(bucket[from+j], bucket[to-j]);
        }
    }

    for(int i=1; i<=n; i++){
        cout << bucket[i] << ' ';
    }

    return 0;
}

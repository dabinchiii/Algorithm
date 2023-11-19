#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> acc(3, vector<int>(n + 1, 0));

    int breedId;
    for(int i=1; i<=n; i++){
        cin >> breedId;

        for(int j=0; j<3; j++){
            acc[j][i] = acc[j][i-1];
        }
        acc[breedId - 1][i]++;
    }

    int a, b;
    for(int i=0; i<q; i++){
        cin >> a >> b;

        cout << acc[0][b] - acc[0][a-1] << ' ';
        cout << acc[1][b] - acc[1][a-1] << ' ';
        cout << acc[2][b] - acc[2][a-1] << '\n';
    }

    return 0;
}

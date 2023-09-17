#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }

    int num;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> num;
            cout << num + mat[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

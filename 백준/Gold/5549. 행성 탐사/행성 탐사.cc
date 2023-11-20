#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> accJ(n+1, vector<int>(m+1, 0));
    vector<vector<int>> accO(n+1, vector<int>(m+1, 0));
    vector<vector<int>> accI(n+1, vector<int>(m+1, 0));

    char ch;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> ch;

            if(ch == 'J') accJ[i][j]++;
            else if(ch == 'O') accO[i][j]++;
            else if(ch == 'I') accI[i][j]++;

            accJ[i][j] += accJ[i][j-1];
            accJ[i][j] += accJ[i-1][j];
            accJ[i][j] -= accJ[i-1][j-1];

            accO[i][j] += accO[i][j-1];
            accO[i][j] += accO[i-1][j];
            accO[i][j] -= accO[i-1][j-1];

            accI[i][j] += accI[i][j-1];
            accI[i][j] += accI[i-1][j];
            accI[i][j] -= accI[i-1][j-1];
        }
    }

    int a, b, c, d;
    int cntJ, cntO, cntI;
    for(int i=0; i<k; i++){
        cin >> a >> b >> c >> d;

        a--; b--;

        cntJ = accJ[c][d];
        cntJ -= accJ[c][b];
        cntJ -= accJ[a][d];
        cntJ += accJ[a][b];

        cntO = accO[c][d];
        cntO -= accO[c][b];
        cntO -= accO[a][d];
        cntO += accO[a][b];

        cntI = accI[c][d];
        cntI -= accI[c][b];
        cntI -= accI[a][d];
        cntI += accI[a][b];

        cout << cntJ << ' ' << cntO << ' ' << cntI << '\n';
    }

    return 0;
}

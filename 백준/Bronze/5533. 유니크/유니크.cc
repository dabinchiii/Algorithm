#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<map<int, int>> m(3);
    vector<vector<int>> score(n, vector<int>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> score[i][j];
            m[j][score[i][j]]++;
        }
    }

    int sum;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=0; j<3; j++){
            if(m[j][score[i][j]] > 1) continue;
            sum += score[i][j];
        }
        cout << sum << '\n';
    }

    return 0;
}

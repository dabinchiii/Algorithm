#include <bits/stdc++.h>
#define INF 50

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> w(n, vector<int>(n));

    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            w[i][j] = (str[j] == 'Y' ? 1 : INF);
        }
    }
    for(int i=0; i<n; i++) w[i][i] = 0;

    vector<vector<int>> dis = w;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int Answer = -1;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(dis[i][j] <= 2) cnt++;
        }
        Answer = max(Answer, cnt);
    }

    cout << Answer;

    return 0;
}

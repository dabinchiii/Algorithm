#include <bits/stdc++.h>
#define MAX_N 50
#define INF 50

using namespace std;

int n;
vector<vector<int>> w(MAX_N + 1, vector<int>(MAX_N + 1, INF));

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++) w[i][i] = 0;

    int a, b;
    while(1){
        cin >> a >> b;
        if(a == -1) break;

        w[a][b] = 1;
        w[b][a] = 1;
    }

    vector<vector<int>> dis = w;

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    vector<int> AnswerList;
    int AnswerScore = INF;
    for(int i=1; i<=n; i++){
        int score = -1;
        for(int j=1; j<=n; j++){
            score = max(score, dis[i][j]);
        }

        if(score < AnswerScore){
            AnswerScore = score;
            AnswerList.clear();
        }
        if(score == AnswerScore){
            AnswerList.push_back(i);
        }
    }

    cout << AnswerScore << ' ' << AnswerList.size() << '\n';
    for(int x : AnswerList) cout << x << ' ';

    return 0;
}

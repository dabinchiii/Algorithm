#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    pair<int, int> family;

    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            arr[i][j] = str[j] - '0';

            if(arr[i][j] == 2){
                family.first = i;
                family.second = j;
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q;
    bool findFood = false;
    int Answer = 0;

    q.push({family, 0});
    visited[family.first][family.second] = true;

    while(!q.empty() && !findFood){
        int currX = q.front().first.first;
        int currY = q.front().first.second;
        int currDis = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nxtX = currX + dx[i];
            int nxtY = currY + dy[i];

            if(nxtX < 0 || nxtX >= n) continue;
            if(nxtY < 0 || nxtY >= m) continue;
            if(visited[nxtX][nxtY]) continue;
            if(arr[nxtX][nxtY] == 1) continue;

            if(arr[nxtX][nxtY] == 0){
                visited[nxtX][nxtY] = true;
                q.push({{nxtX, nxtY}, currDis + 1});
            }
            else{
                findFood = true;
                Answer = currDis + 1;
                break;
            }
        }
    }

    if(findFood) cout << "TAK\n" << Answer;
    else cout << "NIE";

    return 0;
}

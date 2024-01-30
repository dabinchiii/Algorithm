#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> num(n + 1);
    for(int i=1; i<=n; i++){
        cin >> num[i];
    }

    int a, b;
    cin >> a >> b;

    int Answer = -1;
    queue<pair<int, int>> q;
    vector<bool> visited(n + 1, false);

    q.push({a, 0});
    visited[a] = true;

    while(!q.empty()){
        int currX = q.front().first;
        int currJump = q.front().second;
        q.pop();

        if(currX == b){
            Answer = currJump;
            break;
        }

        for(int i=currX + num[currX]; i<=n; i+=num[currX]){
            if(visited[i]) continue;
            visited[i] = true;
            q.push({i, currJump + 1});
        }
        for(int i=currX - num[currX]; i>=1; i-=num[currX]){
            if(visited[i]) continue;
            visited[i] = true;
            q.push({i, currJump + 1});
        }
    }

    cout << Answer;

    return 0;
}

#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int a, b, n, m;
vector<bool> visited(MAX + 1, false);
int nxt, Answer;
queue<pair<int, int>> q;

bool check(int nxt, int currMove){
    if(nxt < 0 || nxt > MAX) return false;
    if(visited[nxt]) return false;

    visited[nxt] = true;
    q.push({nxt, currMove + 1});
    return true;
}

void solve(){
    q.push({n, 0});
    visited[n] = true;

    while(!q.empty()){
        int currX = q.front().first;
        int currMove = q.front().second;
        q.pop();

        if(currX == m){
            Answer = currMove;
            break;
        }
        
        // 술 마셔서 최적화가 안됨ㅎ 
        nxt = currX + 1;
        check(nxt, currMove);

        nxt = currX - 1;
        check(nxt, currMove);

        nxt = currX + a;
        check(nxt, currMove);

        nxt = currX - a;
        check(nxt, currMove);

        nxt = currX + b;
        check(nxt, currMove);

        nxt = currX - b;
        check(nxt, currMove);

        nxt = currX * a;
        check(nxt, currMove);

        nxt = currX * b;
        check(nxt, currMove);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> n >> m;

    solve();

    cout << Answer;

    return 0;
}

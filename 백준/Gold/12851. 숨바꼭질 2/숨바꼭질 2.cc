#include <bits/stdc++.h>
#define MAX 200000
using namespace std;

int n, k;
bool isFound = false;
vector<bool> visited(MAX);
int AnswerT, AnswerCnt;

void bfs(){
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = true;

    while(!q.empty()){
        int currPos = q.front().first;
        int currT = q.front().second;
        q.pop();

        visited[currPos] = true;

        if(!isFound && currPos == k){
            isFound = true;
            AnswerT = currT;
        }
        if(isFound && currPos == k && currT == AnswerT){
            AnswerCnt++;
        }

        int left = currPos - 1;
        int right = currPos + 1;
        int warp = 2 * currPos;

        if(left >= 0 && !visited[left]){
            q.push({left, currT + 1});
        }
        if(right < MAX && !visited[right]){
            q.push({right, currT + 1});
        }
        if(warp < MAX && !visited[warp]){
            q.push({warp, currT + 1});
        }
    }
}

int main(){
    cin >> n >> k;

    bfs();
    cout << AnswerT << ' ' << AnswerCnt;

    return 0;
}

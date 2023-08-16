// 다익스트라, 0-1 BFS!!
// BFS => 시간초과
#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    const int MAX = 2*100000;
    vector<int> dist(MAX+1, INF);
    deque<int> dq;
    dist[n] = 0;
    dq.push_back(n);

    int Answer = -1;
    while(!dq.empty()){
        int curr = dq.front();
        dq.pop_front();

        if(curr == k){
            Answer = dist[k];
            break;
        }

        int teleport = 2 * curr, left = curr - 1, right = curr + 1;
        if(teleport <= MAX && dist[teleport] > dist[curr]){
            dist[teleport] = dist[curr];
            dq.push_front(teleport);
        }
        if(left >= 0 && dist[left] > dist[curr] + 1){
            dist[left] = dist[curr] + 1;
            dq.push_back(left); // 1초 소요되므로 back에 삽입
        }
        if(right <= MAX && dist[right] > dist[curr] + 1){
            dist[right] = dist[curr] + 1;
            dq.push_back(right); // 1초 소요되므로 back에 삽입
        }
    }

    cout << Answer;

    return 0;
}

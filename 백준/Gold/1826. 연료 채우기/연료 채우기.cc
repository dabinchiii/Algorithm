#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX_N 10000

using namespace std;

int N;
pair<int, int> gs[MAX_N + 1];
int dest, ig;
int ans;

void solve(){
    sort(gs, gs + N);
    gs[N] = {dest, 0};
    
    priority_queue<int> pq;
    
    int limit = ig;
    for(int i=0; i<=N; i++){
        while(gs[i].first > limit){ // 못 감
            if(pq.empty()){ // 갈 수 있는 주유소도 없다.
                ans = -1;
                return;
            }
            
            // 지나왔던 주유소 중 가스 가장 많이 주는 곳 방문
            limit += pq.top();
            pq.pop();
            ++ans;
        }
        
        pq.push(gs[i].second);
    }
    
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i=0; i<N; i++) cin >> gs[i].first >> gs[i].second;
    cin >> dest >> ig;
    
    solve();
    
    cout << ans;
    
    return 0;
}

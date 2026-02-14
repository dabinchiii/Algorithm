#include <iostream>
#include <queue>

#define MAX_N 5000000

using namespace std;

int N, L;
int arr[MAX_N], ans[MAX_N];

void solve(){
    priority_queue<pair<int, int>> pq;
    int s = 1 - L;
    for(int s=1-L,e=0; e<N; ++s, ++e){
        pq.push({-arr[e], e});
        while(pq.top().second < s) pq.pop();
        ans[e] = -pq.top().first;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;
    for(int i=0; i<N; i++) cin >> arr[i];
    solve();
    for(int i=0; i<N; i++) cout << ans[i] << ' ';
    
    return 0;
}

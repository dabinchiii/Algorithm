#include <iostream>
#include <queue>

#define MAX_N 5000000

using namespace std;

int N, L;
int arr[MAX_N], ans[MAX_N];

void solve(){
    deque<pair<int, int>> dq;
    for(int s=1-L, e=0; e<N; ++s, ++e){
        while(!dq.empty() && dq.back().first > arr[e]) dq.pop_back();
        dq.push_back({arr[e], e});
        while(dq.front().second < s) dq.pop_front();
        ans[e] = dq.front().first;
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

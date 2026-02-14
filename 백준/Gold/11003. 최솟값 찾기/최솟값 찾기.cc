#include <iostream>
#include <deque>

#define MAX_N 5000000

using namespace std;

int N, L;
int arr[MAX_N], ans[MAX_N];

void solve(){
    deque<int> dq;
    for(int s=1-L, e=0; e<N; ++s, ++e){
        while(!dq.empty() && arr[dq.back()] > arr[e]) dq.pop_back();
        dq.push_back(e);
        while(dq.front() < s) dq.pop_front();
        ans[e] = arr[dq.front()];
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;
    for(int i=0; i<N; i++) cin >> arr[i];
    solve();
    
    string output;
    output.reserve(N * 3);
    for(int i=0; i<N; i++){
        output += to_string(ans[i]);
        output += ' ';
    }
    cout << output;
    
    return 0;
}

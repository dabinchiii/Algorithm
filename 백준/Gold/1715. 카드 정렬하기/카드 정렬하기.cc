#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int num;
    for(int i=0; i<N; i++){
        cin >> num;
        pq.push(num);
    }
    
    int ans = 0;
    while(pq.size() >= 2){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    
    cout << ans;
    
    return 0;
}

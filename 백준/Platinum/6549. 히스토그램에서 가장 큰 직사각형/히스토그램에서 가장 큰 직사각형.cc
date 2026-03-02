#include <iostream>
#include <stack>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N;
long long arr[MAX_N + 2];
long long l[MAX_N + 2], r[MAX_N + 2];
long long ans;

bool solve(){
    cin >> N;
    if(N == 0) return false;
    
    ans = 0;
    arr[0] = arr[N + 1] = 0;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        l[i] = r[i] = i;
    }
    
    stack<pair<int, int>> st; // {idx, h}
    long long curr;
    for(int i=1; i<=N + 1; i++){
        curr = arr[i];
        
        while(!st.empty() && st.top().second > curr){
            int idx = st.top().first;
            st.pop();
            r[idx] = i - 1;
        }
        
        if(!st.empty() && st.top().second == curr) continue;
        
        st.push({i, curr});
    }
    
    for(int i=N; i>=0; i--){
        curr = arr[i];
        
        while(!st.empty() && st.top().second >= curr){
            int idx = st.top().first;
            st.pop();
            l[idx] = i + 1;
        }
        
        if(!st.empty() && st.top().second == curr){
            st.pop();
        }
        
        st.push({i, curr});
    }
    
    for(int i=1; i<=N; i++){
        ans = max(ans, arr[i] * (r[i] - l[i] + 1));
    }
    
    cout << ans << '\n';
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(solve()) {}
    
    return 0;
}

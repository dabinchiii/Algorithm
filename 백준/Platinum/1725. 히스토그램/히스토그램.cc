#include <iostream>
#include <stack>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N;
int arr[MAX_N + 2];
int l[MAX_N + 2], r[MAX_N + 2];
int ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        l[i] = r[i] = i;
    }
    
    stack<pair<int, int>> st; // {idx, h}
    int curr;
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
//        printf("[%d] h=%d, w=%d (%d ~ %d)\n", i, arr[i], r[i] - l[i] + 1, l[i], r[i]);
        ans = max(ans, arr[i] * (r[i] - l[i] + 1));
    }
    cout << ans;
    
    return 0;
}

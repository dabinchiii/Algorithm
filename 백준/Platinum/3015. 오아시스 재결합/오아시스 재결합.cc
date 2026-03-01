#include <iostream>
#include <stack>

using namespace std;

int N;
unsigned long long ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    stack<pair<int, int>> st; // {num, cnt}
    int total = 0;
    int curr;
    for(int i=0; i<N; i++){
        cin >> curr;
        
        while(!st.empty() && st.top().first < curr){
            int cnt = st.top().second;
            ans += cnt;
            
            st.pop();
            total -= cnt;
        }
        
        if(!st.empty() && st.top().first == curr){
            int cnt = st.top().second;
            ans += cnt;
            
            st.pop();
            if(!st.empty()) ++ans;
            
            st.push({curr, cnt + 1});
            ++total;
            
            continue;
        }
        
        if(!st.empty()){
            ++ans;
        }
        
        st.push({curr, 1});
        ++total;
    }
    
    cout << ans;
    
    return 0;
}

#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    stack<int> st;
    long long ans = 0;
    
    int curr;
    for(int i=0; i<N; i++){
        cin >> curr;
        while(!st.empty() && st.top() <= curr) st.pop();
        ans += st.size();
        st.push(curr);
    }
    
    cout << ans;
    
    return 0;
}

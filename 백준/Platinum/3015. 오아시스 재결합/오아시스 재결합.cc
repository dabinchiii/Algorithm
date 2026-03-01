#include <iostream>
#include <stack>

using namespace std;

int N;
long long ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    stack<pair<int, int>> st; // {num, cnt}
    int total = 0, curr;
    for(int i=0; i<N; i++){
        cin >> curr;
        
        while(!st.empty() && st.top().first < curr){ // 나보다 작은 애들은 내가 들어옴으로써 앞으로 선택될 일이 없음
            ans += st.top().second;
            total -= st.top().second;
            st.pop();
        }
        
        if(!st.empty() && st.top().first == curr){ // 스택에서 가장 키가 작은 사람들이 나와 같다
            ans += st.top().second; // 나와 키가 같은 애들은 다 마주볼 수 있다
            
            if(st.size() > 1) ++ans; // 나보다 큰 사람이 있다 => 마지막 한 명만 마주볼 수 있다
    
            st.top().second++;
            ++total;
            
            continue;
        }
        
        // <- 스택에 나보다 큰 사람만 있다
        if(!st.empty()) ++ans; // 마지막 한 명만 마주볼 수 있다
        
        st.push({curr, 1});
        ++total;
    }
    
    cout << ans;
    
    return 0;
}

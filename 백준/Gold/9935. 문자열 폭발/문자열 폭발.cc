#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

string str, target;
string ans;

void solve(){
    int len = (int)str.length();
    
    reverse(str.begin(), str.end());
//    reverse(target.begin(), target.end());
    
    stack<char> s;
    int p = 0;
    
    while(p < len){
        s.push(str[p]);
        p++;
        
        if(s.top() != target[0]) continue;
        
        stack<char> t;
        
        for(int i=0; i<(int)target.length(); i++){
            if(s.empty() || s.top() != target[i]){
                while(!t.empty()){
                    s.push(t.top());
                    t.pop();
                }
                break;
            }
            
            t.push(s.top());
            s.pop();
        }
    }
    
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    
    if(ans.empty()) ans = "FRULA";
    
    return;
}

int main(){
    cin >> str >> target;
    
    solve();
    
    cout << ans;
    
    return 0;
}

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool solve(){
    int n;
    cin >> n;
    
    queue<int> q;
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        q.push(num);
    }
    
    stack<int> s;
    int exp = 1;
    while(exp <= n){
        if(q.empty()){
            if(s.empty()) return false;
            if(s.top() != exp) return false;
        }
        
        if(!s.empty() && s.top() == exp){
            s.pop();
            exp++;
            
            continue;
        }
        
        int curr = q.front();
        q.pop();
        
        if(curr == exp){
            exp++;
        }
        else{
            s.push(curr);
        }
    }
    
    
    
    
    if(!s.empty()) return false;
    
    return true;
}

int main(){
    cout << (solve() ? "Nice" : "Sad");
    
    return 0;
}

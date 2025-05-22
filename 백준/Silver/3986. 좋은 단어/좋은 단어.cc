#include <iostream>
#include <stack>

using namespace std;

bool isGood(string str){
    stack<char> s;
    int len = (int)str.length();
    
    for(int i=0; i<len; i++){
        if(s.empty() || s.top() != str[i]){
            s.push(str[i]);
        }
        else{
            s.pop();
        }
    }
    
    if(!s.empty()) return false;
    
    return true;
}

int main(){
    int n;
    cin >> n;
    
    int ans = 0;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        if(isGood(str)) ans++;
    }
    
    cout << ans;
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string solve(){
    string origin;
    cin >> origin;
    
    int len = (int)origin.length();
    
    int k;
    cin >> k;
    
    int num, head = 0;
    for(int i=0; i<k; i++){
        cin >> num;
        head += num;
        
        if(head < 0) head += (-head / len + 1) * len;
        head %= len;
    }
    
    string ans = origin.substr(head) + origin.substr(0, head);
//    string ans = "";
    
    
    
    return ans;
}

int main(){
    int T;
    cin >> T;
    
    for(int t=1; t<=T; t++){
        cout << solve() << '\n';
    }
    
    return 0;
}

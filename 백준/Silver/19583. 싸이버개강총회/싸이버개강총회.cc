#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main(){
    string s, e, q;
    cin >> s >> e >> q;
    
    string t, name;
    queue<pair<string, string>> log;
    while(cin >> t >> name){
        log.push({t, name});
    }
    
    
    set<string> attd;
    while(!log.empty()){
        pair<string, string> curr = log.front();
        if(curr.first > s) break;
        
        log.pop();
        attd.insert(curr.second);
    }
    
    while(!log.empty()){
        if(log.front().first >= e) break;
        log.pop();
    }
    
    int ans = 0;
    while(!log.empty()){
        pair<string, string> curr = log.front();
        log.pop();
        
        if(curr.first > q) break;
        
        auto it = attd.find(curr.second);
        if(it == attd.end()) continue;
        
        attd.erase(it);
        ans++;
    }
    cout << ans;
    
    return 0;
}

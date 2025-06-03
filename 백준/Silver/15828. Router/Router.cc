#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    queue<int> q;
    int p;
    while(true){
        cin >> p;
        if(p == -1) break;
        
        if(p == 0){
            if(!q.empty()) q.pop();
            continue;
        }
        
        if((int)q.size() == n) continue;
        
        q.push(p);
    }
    
    if(q.empty()) cout << "empty";
    else{
        while(!q.empty()){
            cout << q.front() << ' ';
            q.pop();
        }
    }
    
    return 0;
}

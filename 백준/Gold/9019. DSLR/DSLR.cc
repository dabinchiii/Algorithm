#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string solve(){
    int a, b;
    cin >> a >> b;
    
    vector<bool> visited(10000, false);
    queue<pair<int, string>> q;
    
    q.push({a, ""});
    visited[a] = true;
    
    while(!q.empty()){
        int currN = q.front().first;
        string currComm = q.front().second;
        q.pop();
        
        if(currN == b){
            return currComm;
        }
        
        int d = (2 * currN) % 10000;
        int s = (currN == 0 ? 9999 : currN - 1);
        int l = ((currN % 1000) * 10) + (currN / 1000);
        int r = ((currN % 10) * 1000) + (currN / 10);
        
//        printf("%d %d %d %d\n", d, s, l, r);
        
        if(!visited[d]){
            q.push({d, currComm + "D"});
            visited[d] = true;
        }
        if(!visited[s]){
            q.push({s, currComm + "S"});
            visited[s] = true;
        }
        if(!visited[l]){
            q.push({l, currComm + "L"});
            visited[l] = true;
        }
        if(!visited[r]){
            q.push({r, currComm + "R"});
            visited[r] = true;
        }
    }
    
    return "fail";
}

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        cout << solve() << '\n';
    }
    
    return 0;
}

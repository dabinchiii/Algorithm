#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string solve(){
    int n;
    cin >> n;
    
    queue<int> priorA, priorB;
    int p;
    for(int i=0; i<n; i++){
        cin >> p;
        priorA.push(p);
    }
    for(int i=0; i<n; i++){
        cin >> p;
        priorB.push(p);
    }
    
    vector<char> team(n + 1, 'N');
    
    int cnt = 0; // 선발된 선수
    while(true){
        while(!priorA.empty() && team[priorA.front()] != 'N') priorA.pop();
        team[priorA.front()] = 'A';
        priorA.pop();
        cnt++;
        
        if(cnt == n) break;
        
        while(!priorB.empty() && team[priorB.front()] != 'N') priorB.pop();
        team[priorB.front()] = 'B';
        cnt++;
        
        if(cnt == n) break;
    }
    
    string ans = "";
    for(int i=1; i<=n; i++){
        ans.push_back(team[i]);
    }
    
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

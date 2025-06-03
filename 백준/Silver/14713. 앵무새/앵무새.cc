#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int n;
vector<queue<string>> b(100);
queue<string> target;

bool solve(){
    while(!target.empty()){
        string curr = target.front();
        target.pop();
        
        bool flag = false;
        for(int i=0; i<n; i++){
            if(b[i].front() == curr){
                b[i].pop();
                flag = true;
                break;
            }
        }
        
        if(!flag) return false;
    }
    
    for(int i=0; i<n; i++){
        if(!b[i].empty()) return false;
    }
    return true;
}

int main(){
    cin >> n;
    cin.ignore();
    
    for(int i=0; i<n; i++){
        string str;
        getline(cin, str);
        
        istringstream iss(str);
        
        string token;
        while(iss >> token){
            b[i].push(token);
        }
    }
    
    string targetStr;
    getline(cin, targetStr);
    
    stringstream iss(targetStr);
    string token;
    while(iss >> token){
        target.push(token);
    }
    
    cout << (solve() ? "Possible" : "Impossible");
    
    return 0;
}

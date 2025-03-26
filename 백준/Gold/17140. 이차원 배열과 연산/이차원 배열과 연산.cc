#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int r, c, k;
int board[100][100];
int maxR, maxC;
int ans;

bool cmp(pair<int, int> a, pair<int, int> b){ // {수, 등장 횟수}
    if(a.second != b.second){
        return a.second < b.second;
    }
    
    return a.first < b.first;
}

void operationR(){
    int newMaxC = maxC;
    
    for(int i=0; i<maxR; i++){
        map<int, int> cnt; // {수, 등장 횟수}
        
        for(int j=0; j<maxC; j++){
            if(board[i][j] == 0) continue;
            
            cnt[board[i][j]]++;
            board[i][j] = 0;
        }
        
        int len = static_cast<int>(cnt.size()) * 2;
        len = min(len, 100);
        
        newMaxC = max(newMaxC, len);
        
        vector<pair<int, int>> v; // {수, 등장 횟수}
        for(pair<int, int> curr : cnt){
            v.push_back(curr);
        }
        sort(v.begin(), v.end(), cmp);
        
        int j = 0;
        for(pair<int, int> curr: v){
            board[i][j++] = curr.first;
            board[i][j++] = curr.second;
            
            if(j >= 100) break;
        }
        
    }
    
    maxC = newMaxC;
    
    return;
}
void operationC(){
    int newMaxR = maxR;
    
    for(int i=0; i<maxC; i++){
        map<int, int> cnt; // {수, 등장 횟수}
        
        for(int j=0; j<maxR; j++){
            if(board[j][i] == 0) continue;
            
            cnt[board[j][i]]++;
            board[j][i] = 0;
        }
        
        int len = static_cast<int>(cnt.size()) * 2;
        len = min(len, 100);
        
        newMaxR = max(newMaxR, len);
        
        vector<pair<int, int>> v; // {수, 등장 횟수}
        for(pair<int, int> curr : cnt){
            v.push_back(curr);
        }
        sort(v.begin(), v.end(), cmp);
        
        int j = 0;
        for(pair<int, int> curr: v){
            board[j++][i] = curr.first;
            board[j++][i] = curr.second;
            
            if(j >= 100) break;
        }
    }
    
    maxR = newMaxR;
    
    return;
}

void solve(){
    int currT = 0;
    
    while(true){
        if(board[r][c] == k){
            ans = currT;
            break;
        }
            
        if(maxR >= maxC) operationR();
        else operationC();
        
        currT++;
        
        if(currT > 100){
            ans = -1;
            break;
        }
    }
    
    return;
}

int main(){
    cin >> r >> c >> k;
    r--; c--;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> board[i][j];
        }
    }
    maxR = maxC = 3;
    
    solve();
    
    cout << ans;
    
    return 0;
}

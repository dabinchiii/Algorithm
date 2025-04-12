#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int dc[10000];

int solve(){
    
    int cnt = m, maxCnt = m;
    for(int i=0; i<n; i++){
        cnt += dc[i];
        
        if(cnt < 0) return 0;
        
        if(cnt > maxCnt) maxCnt = cnt;
    }
    
    return maxCnt;
}
int main(){
    cin >> n >> m;
    
    int in, out;
    for(int i=0; i<n; i++){
        cin >> in >> out;
        dc[i] = in - out;
    }
    
    cout << solve();
    
    return 0;
}

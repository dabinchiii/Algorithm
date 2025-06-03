#include <iostream>
#include <map>
#include <queue>

using namespace std;

int n, k;
long long ans;


int main(){
    cin >> n >> k;
    
    map<int, int> cnt;
    queue<int> q;
    
    for(int i=0; i<n; i++){
        string name;
        cin >> name;
        int len = (int)name.length();
        
        ans += cnt[len];
        
        cnt[len]++;
        q.push(len);
        
        if(!q.empty() && (int)q.size() > k){
            cnt[q.front()]--;
            q.pop();
        }
    }
    
    cout << ans;
    
    return 0;
}

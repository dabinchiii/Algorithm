#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    int w[4] = {0, a * 1, b * 2, c * 3};
    
    vector<pair<int, char>> v;
    int s, e;
    for(int i=0; i<3; i++){
        cin >> s >> e;
        v.push_back({s, 's'});
        v.push_back({e, 'e'});
    }
    
    sort(v.begin(), v.end());
    
    int currCnt = 0;
    int ans = 0;
    
    int prevT = 0, currT = 0;
    

    for(int i=0; i<6; i++){
        currT = v[i].first;
        
        ans += (currT - prevT) * w[currCnt];
        
        if(v[i].second == 's') currCnt++;
        else currCnt--;
        
        prevT = currT;
    }
    
    cout << ans;
    
    return 0;
}
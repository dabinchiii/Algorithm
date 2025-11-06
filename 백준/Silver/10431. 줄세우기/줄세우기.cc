#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int TC;
    cin >> TC;
    
    int tmp;
    for(int tc=1; tc<=TC; ++tc){
        cin >> tmp;
        
        vector<int> arr;
        
        int num, pos, ans = 0;
        for(int i=0; i<20; i++){
            cin >> num;
            auto lb = lower_bound(arr.begin(), arr.end(), num);
            pos = (int)(lb - arr.begin());
            ans += i - pos;
            arr.insert(lb, num);
        }
        
        cout << tc << ' ' << ans << '\n';
    }
    
    
    return 0;
}

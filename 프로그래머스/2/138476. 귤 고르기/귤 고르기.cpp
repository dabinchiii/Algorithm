#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> m;
    for(int curr : tangerine) ++m[curr];
    
    vector<int> v;
    for(pair<int, int> curr : m) v.push_back(-curr.second);
    sort(v.begin(), v.end());
    
    int ans = 0, left = k;
    for(int curr : v){
        ++ans;
        left += curr;
        if(left <= 0) break;
    }
    
    return ans;
}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m;
    for(vector<string> &item : clothes){
        ++m[item[1]];
    }
    
    int ans = 1;
    for(pair<string, int> curr : m){
        ans *= curr.second + 1;
    }
    
    --ans;
    
    return ans;
}
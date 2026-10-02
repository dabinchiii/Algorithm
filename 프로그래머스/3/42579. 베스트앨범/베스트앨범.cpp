#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> cnt;
    unordered_map<string, vector<int>> list;
    
    for(int i=0; i<genres.size(); i++){
        cnt[genres[i]] += plays[i];
        list[genres[i]].push_back(i);
    }
    
    vector<string> order;
    for(const auto &curr : cnt) order.push_back(curr.first);
    sort(order.begin(), order.end(), [&](const string &a, const string &b){
        return cnt[a] > cnt[b];
    });
    
    vector<int> ans;
    for(const auto &g : order){
        vector<int> &v = list[g];
        
        sort(v.begin(), v.end(), [&](int a, int b){
            if(plays[a] != plays[b]) return plays[a] > plays[b];
            return a < b;
        });
        
        ans.push_back(v[0]);
        if(v.size() > 1) ans.push_back(v[1]);
    }
    
    return ans;
}
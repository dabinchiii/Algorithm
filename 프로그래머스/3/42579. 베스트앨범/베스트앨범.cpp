#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = genres.size();
    int maxId = 0;
    unordered_map<string, int> cnt, id;
    vector<pair<int, int>> list[100];
    
    for(int i=0; i<n; i++){
        string &g = genres[i];
        int p = plays[i];
        
        if(cnt[g] == 0) id[g] = ++maxId;
            
        cnt[g] += p;
        list[id[g]].push_back({-p, i});
    }
    
    for(int i=1; i<=maxId; i++){
        sort(list[i].begin(), list[i].end());
    }
    
    vector<pair<int, string>> v;
    for(auto curr : cnt) v.push_back({curr.second, curr.first});
    sort(v.begin(), v.end(), greater<>());
    
    vector<int> ans;
    for(auto curr : v){
        int idx = id[curr.second];
        ans.push_back(list[idx][0].second);
        if(list[idx].size() > 1) ans.push_back(list[idx][1].second);
    }
    
    return ans;
}
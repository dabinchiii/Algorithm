#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    vector<pair<int, int>> tg;
    for(vector<int> ms : targets){
        tg.push_back({ms[1], ms[0]});
    }
    sort(tg.begin(), tg.end());
    
    int answer = 0;
    int x = -1;
    for(pair<int, int> curr : tg){
        if(curr.second >= x){
            ++answer;
            x = curr.first;
        }
    }
    
    return answer;
}
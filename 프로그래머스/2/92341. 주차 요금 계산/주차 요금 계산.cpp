#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int, int> info;
int acc[10000];

pair<int, int> parseRecord(string str){
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    int carnum = stoi(str.substr(6, 4));
    
    return {carnum, h * 60 + m};
}
vector<int> solution(vector<int> fees, vector<string> records) {
    for(string str : records){
        auto [num, t] = parseRecord(str);
        
        if(str.back() == 'N'){ // IN
            info[num] = t;
        }
        else{ // OUT
            acc[num] += (t - info[num]);
            info[num] = -1;
        }
    }
    
    vector<int> ans;
    const int et = 24 * 60 - 1;
    for(auto [num, t] : info){
        if(info[num] != -1) acc[num] += et - info[num];
        
        int fee = fees[1];
        acc[num] -= fees[0];
        if(acc[num] > 0){
            int u = (acc[num] + fees[2] - 1) / fees[2];
            fee += u * fees[3];
        }
        
        ans.push_back(fee);
    }
    return ans;
}
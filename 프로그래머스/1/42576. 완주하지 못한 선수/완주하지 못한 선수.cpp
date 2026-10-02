#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    for(string &name : completion) ++m[name];
    for(string &name : participant){
        if(m[name]-- == 0) return name;
    }
    
    return "";
}
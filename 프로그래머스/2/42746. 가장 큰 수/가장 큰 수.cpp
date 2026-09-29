#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}
bool isZero(string str){
    for(char curr : str){
        if(curr != '0') return false;
    }
    return true;
}
string solution(vector<int> numbers) {
    vector<string> v;
    for(int num : numbers) v.push_back(to_string(num));
    
    sort(v.begin(), v.end(), cmp);
    
    string ans = "";
    for(string curr : v) ans += curr;
    
    if(isZero(ans)) return "0";
    
    return ans;
}
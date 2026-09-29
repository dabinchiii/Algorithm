#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b){
    if(a.size() == b.size()) return a > b;
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> v;
    for(int num : numbers) v.push_back(to_string(num));
    
    sort(v.begin(), v.end(), cmp);
    
    string ans = "";
    for(string curr : v) ans += curr;
    
    if(ans[0] == '0' && ans.back() == '0') return "0";
    
    return ans;
}
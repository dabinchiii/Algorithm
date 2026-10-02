#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<string> s;

bool cmp(string &a, string &b){
    return a.size() < b.size();
}
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    for(string num : phone_book){
        for(int i=0; i<num.size(); i++){
            string str = num.substr(0, i + 1);
            if(s.find(str) != s.end()) return false;
        }
        s.insert(num);
    }
    
        
    return true;
}
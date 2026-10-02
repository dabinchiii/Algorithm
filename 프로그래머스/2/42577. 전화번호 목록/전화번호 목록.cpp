#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s(phone_book.begin(), phone_book.end());
    
    for(string &num : phone_book){
        string str;
        for(int i=0; i<num.size() - 1; i++){
            str += num[i];
            if(s.count(str)) return false;
        }
    }
    
    return true;
}
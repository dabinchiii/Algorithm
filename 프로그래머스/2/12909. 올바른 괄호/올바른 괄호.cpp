#include <string>

using namespace std;

bool solution(string s){
    int st = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') ++st;
        else if(st-- == 0) return false;
    }
    
    return st == 0;
}
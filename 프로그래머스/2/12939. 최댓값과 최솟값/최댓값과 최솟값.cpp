#include <string>
#include <vector>
#include <algorithm>

#define INF 999999999

using namespace std;

string solution(string s) {
    s.push_back(' ');
    int maxNum = -INF, minNum = INF;
    int len = s.length();
    
    int start = 0;
    for(int i=0; i<len; i++){
        if(s[i] != ' ') continue;
        
        int num = stoi(s.substr(start, i - start));
        maxNum = max(maxNum, num);
        minNum = min(minNum, num);
        
        ++i;
        start = i;
    }
    
    return to_string(minNum) + " " + to_string(maxNum);
}
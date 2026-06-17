#include <string>
#include <vector>

using namespace std;

int cntZero(string str){
    int cnt = 0;
    for(char ch : str) if(ch == '0') ++cnt;
    return cnt;
}
string toReverseBinaryString(int num){
    string result = "";
    for(;num;num>>=1) result.push_back((num & 1) ? '1' : '0');
    return result;
}
vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while(s.length() > 1){
        int zero = cntZero(s);
        s = toReverseBinaryString(s.length() - zero);
        
        ++answer[0];
        answer[1] += zero;
    }
    
    return answer;
}
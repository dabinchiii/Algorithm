#include <string>
#include <vector>

using namespace std;

int cntZero(string str){
    int cnt = 0;
    for(char ch : str) if(ch == '0') ++cnt;
    return cnt;
}
void convert(int &len, int &zero){
    int num = len - zero;
    for(len=0, zero=0;num;num>>=1, ++len) if(!(num & 1)) ++zero;
}
vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    int len = s.length(), zero = cntZero(s);
    while(len > 1){
        ++answer[0];
        answer[1] += zero;
        convert(len, zero);
    }
    
    return answer;
}

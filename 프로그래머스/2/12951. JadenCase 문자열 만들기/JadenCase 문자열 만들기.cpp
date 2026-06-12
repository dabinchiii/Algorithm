#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string str = " " + s;
    int len = str.length();
    int diff = 'a' - 'A';
    
    for(int i=1; i<len; i++){
        if(str[i] >= 'a' && str[i] <= 'z' && str[i - 1] == ' '){
            str[i] -= diff;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z' && str[i - 1] != ' '){
            str[i] += diff;
        }
    }
    
    return str.substr(1, len - 1);
}
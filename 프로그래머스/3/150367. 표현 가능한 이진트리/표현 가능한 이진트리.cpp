#include <string>
#include <vector>
#include <cmath>

using namespace std;


bool isBinaryTree(string str){
    if(str.length() == 1) return true;
    
    bool allZero = true;
    for(char ch : str){
        if(ch != '0'){
            allZero = false;
            break;
        }
    }
    if(allZero) return true;
    
    int mid = (int)str.length() / 2;
    string left = str.substr(0, mid);
    string right = str.substr(mid + 1);
    
    if(str[mid] == '1' && isBinaryTree(left) && isBinaryTree(right)) return true;
    return false;
    
    return -1;
}

string numberToString(long long number){
    string res = "";
    long long curr = number;
    while(curr > 0){
        res = (curr % 2 ? "1" : "0") + res;
        curr /= 2;
    }
    
    // 패딩 추가
    int len = 2;
    while(true){
        if(res.length() <= len - 1) break;
        len *= 2;
    }
    
    int tmp = len - (int)res.length() - 1;
    while(tmp--){
        res = "0" + res;
    }
    
    return res;
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long number : numbers){
        string str = numberToString(number);
        //cout << str << endl;
        answer.push_back(isBinaryTree(str));
    }
    
    return answer;
}
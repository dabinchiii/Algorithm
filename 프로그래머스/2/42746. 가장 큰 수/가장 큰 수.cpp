#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int cat(int x, int y){
    int p = 1;
    for(int t = y; t > 0; t /= 10) p *= 10;
    if(y == 0) p = 10;
    return x * p + y;
}
bool cmp(int a, int b){
    return cat(a, b) > cat(b, a);
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), cmp);
    
    if(numbers[0] == 0) return "0";
    
    string ans;
    ans.reserve(numbers.size() * 4);
    for(int curr : numbers) ans += to_string(curr);
    
    return ans;
}
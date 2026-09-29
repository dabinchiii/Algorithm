#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

bool cmp(const string &a, const string &b){
    if(a.size() == b.size()) return a > b;
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    int n = numbers.size();
    string arr[MAX_N];
    for(int i=0; i<n; ++i) arr[i] = to_string(numbers[i]);
    
    sort(arr, arr + n, cmp);
    
    if(arr[0] == "0") return "0";
    
    string ans = "";
    for(int i=0; i<n; ++i) ans += arr[i];
    
    return ans;
}
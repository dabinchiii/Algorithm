#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, tg, ans;
vector<int> nums;

void dfs(int cnt, int sum){
    if(cnt == N){
        if(sum == tg) ++ans;
        return;
    }
    
    dfs(cnt + 1, sum - nums[cnt]);
    dfs(cnt + 1, sum + nums[cnt]);
        
    return;
}


int solution(vector<int> numbers, int target) {
    nums = numbers;
    N = numbers.size();
    tg = target;
    
    dfs(0, 0);
    
    return ans;
}
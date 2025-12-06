#include <string>
#include <vector>

using namespace std;

int N;
vector<int> times;

bool check(long long t){
    long long cnt = 0;
    for(int curr : times) cnt += t / curr;
    return cnt >= N;
}

long long solution(int n, vector<int> _times) {
    N = n;
    times = _times;
    
    long long left = 1, right = 1000000000000000000;
    long long ans = right;
    while(left <= right){
        long long mid = left + ((right - left) >> 1);
        if(check(mid)){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    return ans;
}

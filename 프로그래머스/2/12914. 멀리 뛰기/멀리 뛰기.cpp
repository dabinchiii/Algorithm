#include <vector>

#define MOD 1234567

using namespace std;

long long solution(int n) {
    long long ppre, pre, curr;
    ppre = pre = curr = 1;
    for(int i=2; i<=n; ++i){
        curr = (ppre + pre) % MOD;
        ppre = pre;
        pre = curr;
    }
    
    return curr;
}
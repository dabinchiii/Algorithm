#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B){
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int len = A.size();
    int sum1 = 0, sum2 = 0;
    for(int i=0; i<len; i++){
        sum1 += A[i] * B[len - i - 1];
        sum2 += B[i] * A[len - i - 1];
    }
    
    return min(sum1, sum2);
}
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    
    for(int curr : scoville){
        pq.push(-curr);
    }
    
    while(-pq.top() < K){
        int res = pq.top();
        pq.pop();
        
        if(pq.empty()) return -1;
        
        res += pq.top() << 1;
        pq.pop();
        
        pq.push(res);
        ++answer;
    }
    
    
    return answer;
}
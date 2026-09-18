#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int N = priorities.size();
    queue<int> q;
    priority_queue<int> pq;
    
    for(int i=0;i <N; i++){
        q.push(i);
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        if(pq.top() == priorities[curr]){
            pq.pop();
            if(curr == location) return N - q.size();
        }    
        else{
            q.push(curr);
        }
        
    }
    
    return -1;
}
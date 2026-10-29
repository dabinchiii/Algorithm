#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    
    int N = jobs.size();
    priority_queue<pair<int, int>> pq;
    
    int t = 0, total = 0, idx = 0, done = 0;
    
    while(done < N){
        while(idx < N && jobs[idx][0] <= t){
            pq.push({-jobs[idx][1], -jobs[idx][0]});
            ++idx;
        }
        
        if(pq.empty()){
            t = jobs[idx][0];
            continue;
        }
        
        pair<int, int> curr = pq.top();
        pq.pop();
        
        t -= curr.first;
        total += t + curr.second;
        ++done;
    }
    
    return total / N;
}
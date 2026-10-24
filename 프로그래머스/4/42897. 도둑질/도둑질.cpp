#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    int N = money.size();
    int prev0, prev1, pprev0;
    int curr0, curr1;
    
    pprev0 = prev1 = 0;
    prev0 = money[0];
    for(int i=1; i<N; i++){
        curr0 = money[i] + max(pprev0, prev1);
        curr1 = max(prev0, prev1);
        
        pprev0 = prev0;
        prev0 = curr0;
        prev1 = curr1;
    }
    
    int ans = max(prev1, pprev0);
    
    pprev0 = prev1 = prev0 = 0;
    for(int i=1; i<N; i++){
        curr0 = money[i] + max(pprev0, prev1);
        curr1 = max(prev0, prev1);
        
        pprev0 = prev0;
        prev0 = curr0;
        prev1 = curr1;
    }
    
    ans = max(ans, max(prev0, prev1));
    
    return ans;
}
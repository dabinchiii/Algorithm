#include <vector>

using namespace std;

bool l[31], r[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    for(int curr : lost) l[curr] = true;
    for(int curr : reserve){
        if(l[curr]) l[curr] = false;
        else r[curr] = true;
    }
    
    int ans = n;
    for(int i=1; i<=n; i++){
        if(!l[i]) continue;
        
        if(i - 1 > 0 && r[i - 1]) r[i - 1] = false;
        else if(i + 1 <= n && r[i + 1]) r[i + 1] = false;
        else --ans;
    }
        
    return ans;
}
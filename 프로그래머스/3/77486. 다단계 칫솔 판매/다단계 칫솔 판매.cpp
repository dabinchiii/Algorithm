#include <string>
#include <vector>
#include <unordered_map>

#define MAX_N 10000

using namespace std;

unordered_map<string, int> nameToId;

int N;
int parent[MAX_N + 1], profit[MAX_N + 1];

void distribute(int id, int value){
    int curr = id;
    while(value > 0 && curr != -1){
        profit[curr] += value;
        value /= 10;
        profit[curr] -= value;
        curr = parent[curr];
    }
    
    return;
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    N = enroll.size();
    
    for(int i=0; i<N; i++) nameToId[enroll[i]] = i;
    nameToId["-"] = N;
    
    for(int i=0; i<N; i++){
        parent[i] = nameToId[referral[i]];
    }
    parent[N] = -1;
    
    for(int i=0; i<seller.size(); i++){
        distribute(nameToId[seller[i]], amount[i] * 100);
    }
    
    vector<int> ans(profit, profit + N);
    
    return ans;
}
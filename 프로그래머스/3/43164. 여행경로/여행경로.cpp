#include <string>
#include <vector>
#include <map>

#define MAX ('Z' << 10 | 'Z' << 5 | 'Z')

using namespace std;

int N; // 항공권 수
map<int, int> g[MAX + 1];
int path[100000000];

bool dfs(int cnt){
    if(cnt == N + 1){
        return true;
    }
    
    int curr = path[cnt - 1];
    for(auto [nxt, lft] : g[curr]){
        if(lft == 0) continue;
        
        --g[curr][nxt];
        path[cnt] = nxt;
        
        if(dfs(cnt + 1)) return true;
        
        ++g[curr][nxt];
    }
    
    return false;
}

int encode(string name){
    int res = 0;
    res |= (name[0] - 'A') << 10;
    res |= (name[1] - 'A') << 5;
    res |= (name[2] - 'A');
    return res;
}
string decode(int num){
    string res;
    res += 'A' + ((num >> 10) & 31);
    res += 'A' + ((num >> 5) & 31);
    res += 'A' + (num & 31);
    return res;
}
vector<string> solution(vector<vector<string>> tickets) {
    N = tickets.size();
    
    for(vector<string> tck : tickets){
        int a = encode(tck[0]);
        int b = encode(tck[1]);
        ++g[a][b];
    }
    
    path[0] = encode("ICN");
    dfs(1);
    
    vector<string> ans(N + 1);
    for(int i=0; i<=N; i++){
        ans[i] = decode(path[i]);
    }
    return ans;
}
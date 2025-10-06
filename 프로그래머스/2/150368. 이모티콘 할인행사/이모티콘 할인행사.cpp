#include <string>
#include <vector>

using namespace std;

// 할인율은 10%, 20%, 30%, 40% + 0%?
// 각 사용자들은 자신의 기준을 만족하는 이모티콘 모두 구매
// 기준: 일정 비율 이상 할인
// 기준에 따라 구매한 비용의 합이 일정 가격 이상이 된다면, 모두 취소 후 이모티콘 플러스 가입
// n <= 100, m <= 7
// => 7^4 완탐

int N, M;
vector<vector<int>> users;
vector<int> emoticons;
pair<int, int> ans;

int dis[8];

void dfs(int cnt){
    if(cnt == M){
        int cntPlus = 0, total = 0;
        for(int i=0; i<N; i++){ // 사용자별
            
            int sum = 0;
            for(int j=0; j<M; j++){
                if(dis[j] < users[i][0]) continue;
                sum += (100 - dis[j]) * 0.01 * emoticons[j];
            }
            
            if(sum >= users[i][1]){ // 플러스 가입
                ++cntPlus;
            }
            else{
                total += sum;
            }
        }

        if(cntPlus > ans.first){
            ans = {cntPlus, total};
        }
        else if(cntPlus == ans.first){
            if(total > ans.second){
                ans = {cntPlus, total};
            }
        }
        
        return;
    }
    
    for(int i=1; i<=4; i++){
        dis[cnt] = 10 * i;
        dfs(cnt + 1);
        dis[cnt] = 0;
    }
    
    return;
}
vector<int> solution(vector<vector<int>> _users, vector<int> _emoticons) {
    N = (int)_users.size();
    M = (int)_emoticons.size();
    users = _users;
    emoticons = _emoticons;
    
    ans = {-1, -1};
    
    dfs(0);
    
    
    vector<int> answer = {ans.first, ans.second};
    return answer;
}
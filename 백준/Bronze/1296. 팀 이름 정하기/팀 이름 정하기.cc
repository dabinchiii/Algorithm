#include <iostream>
#include <vector>

using namespace std;

string yd, ans;
string names[50];
int N;

void solve(){
    vector<int> cntYd(4, 0);
    for(char ch : yd){
        if(ch == 'L') ++cntYd[0];
        else if(ch == 'O') ++cntYd[1];
        else if(ch == 'V') ++cntYd[2];
        else if(ch == 'E') ++cntYd[3];
    }
    
    int maxScore = -1;
    for(int i=0; i<N; i++){
        vector<int> cnt = cntYd;
        for(char ch : names[i]){
            if(ch == 'L') ++cnt[0];
            else if(ch == 'O') ++cnt[1];
            else if(ch == 'V') ++cnt[2];
            else if(ch == 'E') ++cnt[3];
        }
        
        int score = 1;
        for(int j=0; j<4; j++){
            for(int k=j+ 1; k<4; k++){
                score *= cnt[j] + cnt[k];
                score %= 100;
            }
        }
        
        if(score > maxScore){
            maxScore = score;
            ans = names[i];
        }
        else if(score == maxScore){
            if(names[i] < ans) ans = names[i];
        }
        
    }
    
    return;
}
int main(){
    cin >> yd >> N;
    for(int i=0; i<N; i++) cin >> names[i];
    solve();
    cout << ans;
    
    return 0;
}

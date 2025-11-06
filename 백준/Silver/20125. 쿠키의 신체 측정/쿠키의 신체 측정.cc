#include <iostream>

using namespace std;

struct loc{
    int r, c;
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int N;
bool board[1002][1002];

int cntLen(loc start, int d){
    int nr = start.r, nc = start.c;
    int cnt = 0;
    while(true){
        nr += dr[d];
        nc += dc[d];
        if(!board[nr][nc]) break;
        ++cnt;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    string line;
    loc heart = {-1, -1};
    for(int i=1; i<=N; i++){
        cin >> line;
        
        for(int j=1; j<=N; j++){
            board[i][j] = line[j - 1] == '*';
            if(heart.r == -1 && board[i - 1][j]) heart = {i, j};
        }
    }
    
    int leftArm = cntLen(heart, 2);
    int rightArm = cntLen(heart, 3);
    int waist = cntLen(heart, 1);
    int leftLeg = cntLen({heart.r + waist, heart.c - 1}, 1);
    int rightLeg = cntLen({heart.r + waist, heart.c + 1}, 1);
    
    cout << heart.r << ' ' << heart.c << '\n';
    cout << leftArm << ' ' << rightArm << ' ' << waist << ' ' << leftLeg << ' ' << rightLeg;
    
    return 0;
}

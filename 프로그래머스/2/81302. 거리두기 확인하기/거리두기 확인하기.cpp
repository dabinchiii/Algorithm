#include <string>
#include <vector>

using namespace std;

/*
- - 2 - -
- 2 1 2 -
2 1 * 1 2
- 2 1 2 -
- - 2 - -
상하좌우 1칸 거리: 무조건 안됨
대각선: 맨해튼 거리 2. 끼인 칸들이 "모두" 파티션일 경우만 가능
상하좌우 2칸 거리: 끼인 칸이 파티션일 경우만 가능
*/

// 상하좌우(1칸 거리), 대각선, 상하좌우(2칸 거리)
int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1, -2, 2, 0, 0};
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1, 0, 0, -2, 2};

bool check(int r, int c){
    return r >= 0 && r < 5 && c >= 0 && c < 5;
}

bool checkRoom(vector<string> place){
    for(int r=0; r<5; r++){
        for(int c=0; c<5; c++){
            if(place[r][c] != 'P') continue;
            
            for(int d=0; d<4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(!check(nr, nc)) continue;
                
                if(place[nr][nc] == 'P') return false;
            }
            
            for(int d=4; d<8; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(!check(nr, nc)) continue;
                if(place[nr][nc] != 'P') continue;
                
                if(place[nr][c] != 'X' || place[r][nc] != 'X') return false;
            }
            
            for(int d=8; d<12; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(!check(nr, nc)) continue;
                if(place[nr][nc] != 'P') continue;
                
                int br = r + dr[d - 8];
                int bc = c + dc[d - 8];
                if(place[br][bc] != 'X') return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place : places){
        answer.push_back(checkRoom(place) ? 1 : 0);
    }
    return answer;
}
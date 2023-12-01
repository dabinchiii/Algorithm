#include <bits/stdc++.h>

using namespace std;

typedef struct pos{
    char col;
    int row;
}pos;

bool operator!=(pos a, pos b){
    return !(a.col == b.col && a.row == b.row);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pos king, stone;
    int n;

    cin >> king.col >> king.row;
    cin >> stone.col >> stone.row;
    cin >> n;

    string command;
    int dx, dy;
    for(int i=0; i<n; i++){
        cin >> command;

        dx = 0; dy = 0;
        for(int j=0; j<command.length(); j++){
            switch(command[j]){
                case 'R': dx = 1; break;
                case 'L': dx = -1; break;
                case 'B': dy = -1; break;
                case 'T': dy = 1; break;
            }
        }

        pos nxtKing = {king.col + dx, king.row + dy};

        if(nxtKing.col < 'A' || nxtKing.col > 'H') continue;
        if(nxtKing.row < 1 || nxtKing.row > 8) continue;

        if(nxtKing != stone){
            king = nxtKing;
            continue;
        }

        pos nxtStone = {stone.col + dx, stone.row + dy};
        if(nxtStone.col < 'A' || nxtStone.col > 'H') continue;
        if(nxtStone.row < 1 || nxtStone.row > 8) continue;

        king = nxtKing;
        stone = nxtStone;
    }

    cout << king.col << king.row << '\n';
    cout << stone.col << stone.row;

    return 0;
}

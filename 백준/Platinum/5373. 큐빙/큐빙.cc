#include <iostream>
#include <map>

using namespace std;

#define U 0
#define D 1
#define F 2
#define B 3
#define L 4
#define R 5

#define U_SIDE 0
#define R_SIDE 1
#define L_SIDE 2
#define D_SIDE 3

typedef struct cube_junc{
    int face;
    int side;
} cube_junc;

int side[4][3] = {
    {0, 1, 2}, // 0: up
    {2, 5, 8}, // 1: right
    {6, 3, 0}, // 2: left
    {8, 7, 6} // 3: down
};

// B F 방향 같게
cube_junc junc[6][4] = {
    {{B, U_SIDE}, {R, U_SIDE}, {F, U_SIDE}, {L, U_SIDE}}, // U => B up, R up, F up, L up
    {{F, D_SIDE}, {R, D_SIDE}, {B, D_SIDE}, {L, D_SIDE}}, // D => F down, R down, B down, L down
    {{U, D_SIDE}, {R, L_SIDE}, {D, U_SIDE}, {L, R_SIDE}}, // F => U down, R left, D up, L right
    {{U, U_SIDE}, {L, L_SIDE}, {D, D_SIDE}, {R, R_SIDE}}, // B => U up, L left, D down, R right
    {{U, L_SIDE}, {F, L_SIDE}, {D, L_SIDE}, {B, R_SIDE}}, // L => U left, F left, D left, B right
    {{U, R_SIDE}, {B, L_SIDE}, {D, R_SIDE}, {F, R_SIDE}} // R => U right, B left, D right, F right
};

map<char, int> faceNum;

int n;
string comm[1000];
char cube[6][9];

void copySide(int face, int fromIdx, int toIdx){
    cube_junc from = junc[face][fromIdx];
    cube_junc to = junc[face][toIdx];
    
    for(int i=0; i<3; i++){
        cube[to.face][side[to.side][i]] = cube[from.face][side[from.side][i]];
    }
    return;
}
void spinCw(int face){ // 시계방향(+)
    char tmp[3];
    for(int i=0; i<2; i++){
        tmp[i] = cube[face][side[U_SIDE][i]];
    }
    for(int i=0; i<2; i++){
        cube[face][side[U_SIDE][i]] = cube[face][side[L_SIDE][i]];
    }
    for(int i=0; i<2; i++){
        cube[face][side[L_SIDE][i]] = cube[face][side[D_SIDE][i]];
    }
    for(int i=0; i<2; i++){
        cube[face][side[D_SIDE][i]] = cube[face][side[R_SIDE][i]];
    }
    for(int i=0; i<2; i++){
        cube[face][side[R_SIDE][i]] = tmp[i];
    }
    
    cube_junc from, to;
    
    from = junc[face][0];
    for(int i=0; i<3; i++){
        tmp[i] = cube[from.face][side[from.side][i]];
    }
    copySide(face, 3, 0);
    copySide(face, 2, 3);
    copySide(face, 1, 2);
    
    to = junc[face][1];
    for(int i=0; i<3; i++){
        cube[to.face][side[to.side][i]] = tmp[i];
    }
    
    return;
}
void spinCcw(int face){ // 반시계방향(-)
    char tmp[3];
    for(int i=0; i<2; i++){
        tmp[i] = cube[face][side[U_SIDE][i]];
    }
    for(int i=0; i<2; i++){
        cube[face][side[U_SIDE][i]] = cube[face][side[R_SIDE][i]];
    }
    for(int i=0; i<2; i++){
        cube[face][side[R_SIDE][i]] = cube[face][side[D_SIDE][i]];
    }
    for(int i=0; i<2; i++){
        cube[face][side[D_SIDE][i]] = cube[face][side[L_SIDE][i]];
    }
    for(int i=0; i<2; i++){
        cube[face][side[L_SIDE][i]] = tmp[i];
    }
    
    cube_junc from, to;
    
    from = from = junc[face][0];
    for(int i=0; i<3; i++){
        tmp[i] = cube[from.face][side[from.side][i]];
    }
    
    copySide(face, 1, 0);
    copySide(face, 2, 1);
    copySide(face, 3, 2);
    
    to = junc[face][3];
    for(int i=0; i<3; i++){
        cube[to.face][side[to.side][i]] = tmp[i];
    }
    
    return;
}
void solve(){
    for(int i=0; i<n; i++){
        if(comm[i][1] == '+') spinCw(faceNum[comm[i][0]]);
        else spinCcw(faceNum[comm[i][0]]);
    }
    
    return;
}

void initCube(){
    for(int i=0; i<9; i++){
        cube[U][i] = 'w';
        cube[D][i] = 'y';
        cube[F][i] = 'r';
        cube[B][i] = 'o';
        cube[L][i] = 'g';
        cube[R][i] = 'b';
    }
    return;
}
int main(){
    faceNum['U'] = U;
    faceNum['D'] = D;
    faceNum['F'] = F;
    faceNum['B'] = B;
    faceNum['L'] = L;
    faceNum['R'] = R;
    
    int T;
    cin >> T;
    
    for(int test_case=1; test_case<=T; test_case++){
        initCube();
        
        cin >> n;
        for(int i=0; i<n; i++) cin >> comm[i];
        
        solve();
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout << cube[U][i * 3 + j];
            }
            cout << '\n';
        }
    }
    
    return 0;
}
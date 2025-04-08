#include <iostream>

using namespace std;

int main(){
    int apw, ahp, bpw, bhp;
    cin >> apw >> ahp >> bpw >> bhp;
    
    int cntDead = 0;
    while(!cntDead){
        ahp -= bpw;
        bhp -= apw;
        
        if(ahp <= 0) cntDead++;
        if(bhp <= 0) cntDead++;
    }
    
    if(cntDead == 2) cout << "DRAW";
    else if(ahp > 0) cout << "PLAYER A";
    else cout << "PLAYER B";
    
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct time{
    int h, m, s;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    struct time startT[3], endT[3];

    for(int i=0; i<3; i++){
        cin >> startT[i].h >> startT[i].m >> startT[i].s;
        cin >> endT[i].h >> endT[i].m >> endT[i].s;
    }

    for(int i=0; i<3; i++){
        endT[i].s -= startT[i].s;
        if(endT[i].s < 0){
            endT[i].s += 60;
            endT[i].m--;
        }

        endT[i].m -= startT[i].m;
        if(endT[i].m < 0){
            endT[i].m += 60;
            endT[i].h--;
        }

        endT[i].h -= startT[i].h;

        cout << endT[i].h << ' ' << endT[i].m << ' ' << endT[i].s << '\n';
    }



    return 0;
}

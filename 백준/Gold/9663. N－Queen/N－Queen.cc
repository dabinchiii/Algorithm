#include <bits/stdc++.h>
#define MAX_N 14

using namespace std;

int n;
bool col[MAX_N];
bool cross1[2 * MAX_N - 1]; // 오른쪽 아래로 향하는 사선
bool cross2[2 * MAX_N - 1]; // 오른쪽 위로 향하는 사선
int ans;

void bt(int cnt){
    if(cnt == n){
        ans++;
        return;
    }

    int currLow = cnt + 1;

    for(int currCol=0; currCol<n; currCol++){
        int currCross1 = (currLow - currCol) + n - 1;
        int currCross2 = currLow + currCol;

        if(col[currCol]) continue;
        if(cross1[currCross1]) continue;
        if(cross2[currCross2]) continue;

        col[currCol] = cross1[currCross1] = cross2[currCross2] = true;
        bt(cnt + 1);
        col[currCol] = cross1[currCross1] = cross2[currCross2] = false;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    bt(0);

    cout << ans;

    return 0;
}

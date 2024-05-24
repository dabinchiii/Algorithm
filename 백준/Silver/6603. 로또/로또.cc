#include <bits/stdc++.h>

#define MAX_K 12

using namespace std;

int k, s[MAX_K];
int ans[6];

void bt(int cnt, int idx){
    if(cnt == 6){
        for(int i=0; i<6; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=idx; i<k; i++){
        ans[cnt] = s[i];
        bt(cnt + 1, i + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        cin >> k;
        if(k == 0) break;

        for(int i=0; i<k; i++){
            cin >> s[i];
        }

        bt(0, 0);
        cout << '\n';
    }

    return 0;
}

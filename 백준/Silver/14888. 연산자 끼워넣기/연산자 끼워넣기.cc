#include <bits/stdc++.h>

#define MAX_NUMS 100
#define MAX_ANS 1000000000
#define MIN_ANS -1000000000

using namespace std;

int n;
int nums[MAX_NUMS];
int opers[4]; // +, -, *, /

int ansMax = MIN_ANS, ansMin = MAX_ANS;

void bt(int idx, int value){
    if(idx == n){
        ansMax = max(ansMax, value);
        ansMin = min(ansMin, value);
        return;
    }

    for(int i=0; i<4; i++){
        if(opers[i] <= 0) continue;

        opers[i]--;

        switch(i){
        case 0: // +
            bt(idx + 1, value + nums[idx]);
            break;
        case 1: // -
            bt(idx + 1, value - nums[idx]);
            break;
        case 2: // *
            bt(idx + 1, value * nums[idx]);
            break;
        case 3: // /
            bt(idx + 1, value / nums[idx]);
            break;
        }

        opers[i]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    for(int i=0; i<4; i++){
        cin >> opers[i];
    }

    bt(1, nums[0]);

    cout << ansMax << '\n' << ansMin;

    return 0;
}

#include <bits/stdc++.h>
#define MAX_N 20

using namespace std;

int n;
int nums[] = {1, 5, 10, 50};
int seq[MAX_N];
set<int> s;

void bt(int cnt){
    if(cnt == n){
        int num = 0;
        for(int i=0; i<n; i++) num += nums[seq[i]];
        s.insert(num);

        return;
    }

    for(int i=seq[max(0, cnt - 1)]; i<4; i++){
        seq[cnt] = i;
        bt(cnt + 1);
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    bt(0);

    cout << s.size();

    return 0;
}

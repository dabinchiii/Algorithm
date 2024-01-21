#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int curr = 0, dir = 1;
    for(int i=1; i<=n; i++){
        curr += dir;

        if(curr >= 1 && curr <= 5) continue;
        dir *= -1;
        curr += 2 * dir;
    }

    cout << curr;

    return 0;
}

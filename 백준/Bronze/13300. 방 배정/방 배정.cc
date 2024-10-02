#include <bits/stdc++.h>

using namespace std;

int n, k;
int student[7][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    int s, y;
    for(int i=0; i<n; i++){
        cin >> s >> y;
        student[y][s]++;
    }

    int ans = 0;
    for(int i=1; i<=6; i++){
        ans += student[i][0] / k;
        ans += student[i][0] % k ? 1 : 0;

        ans += student[i][1] / k;
        ans += student[i][1] % k ? 1 : 0;
    }

    cout << ans;

    return 0;
}

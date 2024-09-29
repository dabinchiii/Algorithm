#include <bits/stdc++.h>

using namespace std;

int h, w;
int block[500];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;
    for(int i=0; i<w; i++){
        cin >> block[i];
    }

    int ans = 0;
    for(int i=1; i<w - 1; i++){
        int leftHigh = 0, rightHigh = 0;

        for(int j=i - 1; j>=0; j--) leftHigh = max(leftHigh, block[j]);
        for(int j=i + 1; j<w; j++) rightHigh = max(rightHigh, block[j]);

        ans += max(0, min(leftHigh, rightHigh) - block[i]);
    }

    cout << ans;

    return 0;
}

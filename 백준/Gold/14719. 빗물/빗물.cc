#include <bits/stdc++.h>

using namespace std;

int h, w;
int block[500];
int water[500];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;
    for(int i=0; i<w; i++){
        cin >> block[i];
    }

    for(int i=0; i<w; i++){
        for(int j=i + 1; j<w; j++){
            if(block[j] < block[i]) continue;

            for(int k=i + 1; k<j; k++){
                water[k] = max(water[k], block[i] - block[k]);
            }

            break;
        }
    }

    for(int i=w-1; i>=0; i--){
        for(int j=i - 1; j>=0; j--){
            if(block[j] < block[i]) continue;

            for(int k=i - 1; k>j; k--){
                water[k] = max(water[k], block[i] - block[k]);
            }

            break;
        }
    }

    int ans = 0;
    for(int i=0; i<w; i++){
        ans += water[i];
    }

    cout << ans;

    return 0;
}

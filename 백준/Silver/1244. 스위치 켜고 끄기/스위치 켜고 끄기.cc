#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<bool> s(n+1);
    int state;
    for(int i=1; i<=n; i++){
        cin >> state;
        s[i] = (state == 1 ? true : false);
    }

    int m;
    cin >> m;
    int gender, num;
    for(int i=0; i<m; i++){
        cin >> gender >> num;

        if(gender == 1){
            int currIdx = num;
            while(currIdx <= n){
                s[currIdx] = !s[currIdx];
                currIdx += num;
            }
        }
        else{
            int dist = 0;
            int left, right;
            while(true){
                left = num - dist;
                right = num + dist;

                if(left < 1 || right > n) break;
                if(s[left] != s[right]) break;

                s[left] = !s[left];
                s[right] = s[left];
                dist++;
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << s[i] << (i % 20 == 0 ? '\n' : ' ');
    }

    return 0;
}

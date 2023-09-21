#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> zeros(MAX+1, 0);
    zeros[0] = 1;
    for(int i=1; i<=MAX; i++){
        int curr = i;
        while(curr > 0){
            if(curr % 10 == 0) zeros[i]++;
            curr /= 10;
        }
    }

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n, m;
        cin >> n >> m;

        int Answer = 0;
        for(int i=n; i<=m; i++){
            Answer += zeros[i];
        }

        cout << Answer << '\n';
    }

    return 0;
}

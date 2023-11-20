#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> acc(n + 1);
        acc[0] = 0;
        for(int i=1; i<=n; i++){
            cin >> acc[i];
            acc[i] += acc[i-1];
        }

        if(n == m){
            cout << (acc[n] < k ? 1 : 0) << '\n';
            continue;
        }
        long long sum, cnt = 0;
        for(int left=1; left<=n; left++){
            int right = left + m - 1;
            if(right <= n){
                sum = acc[right] - acc[left - 1];
            }
            else{
                sum = acc[n] - acc[left - 1];
                sum += acc[right - n];
            }

            if(sum < k) cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}

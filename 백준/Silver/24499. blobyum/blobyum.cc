#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> acc(n + 1);
    acc[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> acc[i];
        acc[i] += acc[i - 1];
    }

    int Answer = -1;
    int sum;
    for(int i=1; i<=n; i++){
        int right = i + k - 1;

        if(right <= n){
            sum = acc[right] - acc[i - 1];
        }
        else{
            sum = acc[n] - acc[i - 1] + acc[right - n];
        }

        Answer = max(Answer, sum);
    }

    cout << Answer;

    return 0;
}

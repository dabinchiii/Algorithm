#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<bool> arr(n+1, true);
    int cnt = 0, Answer = 0;

    for(int i=2; i<=n && Answer==0; i++){
        if(!arr[i]) continue;

        for(int j=i; j<=n; j+=i){
            if(arr[j]){
                cnt++;
                arr[j] = false;

                if(cnt == k){
                    Answer = j;
                    break;
                }
            }
        }
    }

    cout << Answer;

    return 0;
}

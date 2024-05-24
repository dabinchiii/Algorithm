#include <bits/stdc++.h>
#define MAX_N 8

using namespace std;

int n;
int arr[MAX_N];
int seq[MAX_N], ans = -1;
bool visited[MAX_N];

int getValue(){
    int sum = 0;
    for(int i=1; i<n; i++){
        sum += abs(seq[i - 1] - seq[i]);
    }
    return sum;
}

void bt(int cnt){
    if(cnt == n){
        ans = max(ans, getValue());
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;

        seq[cnt] = arr[i];
        visited[i] = true;
        bt(cnt + 1);
        visited[i] = false;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    bt(0);

    cout << ans;

    return 0;
}

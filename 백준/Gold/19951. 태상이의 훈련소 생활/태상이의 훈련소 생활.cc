#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    vector<int> command(n+2, 0);
    int a, b, k;
    for(int i=0; i<m; i++){
        cin >> a >> b >> k;
        command[a] += k;
        command[b+1] -= k;
    }

    int curr = 0;
    for(int i=1; i<=n; i++){
        curr += command[i];
        cout << arr[i] + curr << ' ';
    }

    return 0;
}

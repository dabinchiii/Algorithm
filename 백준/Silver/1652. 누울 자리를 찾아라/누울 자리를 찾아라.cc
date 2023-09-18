#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> arr(n+2);

    string padding = "";
    for(int i=0; i<n+2; i++){
        padding += "X";
    }
    arr[0] = padding;
    arr[n+1] = padding;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
        arr[i] = "X" + arr[i] + "X";
    }

    int h = 0, v = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j] != arr[i][j-1] && arr[i][j] == '.' && arr[i][j+1] == '.') h++;
            if(arr[j][i] != arr[j-1][i] && arr[j][i] == '.' && arr[j+1][i] == '.') v++;
        }
    }

    cout << h << ' ' << v << '\n';

    return 0;
}

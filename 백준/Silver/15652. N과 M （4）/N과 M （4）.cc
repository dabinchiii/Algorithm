#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[9];

void f(int k){
    if(k == m){
        for(int i=0; i<m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int num = arr[k-1];
    if(k==0) num = 1;
    for(int i=num; i<=n; i++){
        arr[k] = i;
        f(k+1);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    f(0);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[8];
int arr[8];

void f(int k){
    if(k == m){
        for(int i=0; i<m; ++i)
            cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    int s = 0;
    if(k > 0) s = arr[k-1];
    for(int i=s; i<n; i++){
        arr[k] = i;
        f(k+1);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    sort(num, num+n);

    f(0);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int b, c;
    cin >> b >> c;

    long long Answer = 0;

    for(int i=0; i<n; i++){
        Answer++;
        a[i] -= b;

        if(a[i] <= 0) continue;

        Answer += (a[i] % c == 0 ? a[i] / c : a[i] / c + 1);
    }

    cout << Answer;

    return 0;
}

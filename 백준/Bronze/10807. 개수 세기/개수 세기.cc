#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> m;
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        m[num]++;
    }

    int v;
    cin >> v;

    cout << m[v];

    return 0;
}

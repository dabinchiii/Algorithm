#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int w = pow(2, n);
    int Answer = pow(w+1, 2);
    cout << Answer;

    return 0;
}

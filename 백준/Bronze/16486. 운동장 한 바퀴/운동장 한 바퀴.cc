#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const double pi = 3.141592;
    int d1, d2;
    cin >> d1 >> d2;

    double Answer = 0;
    Answer += 2 * d1;
    Answer += pi * (2 * d2);

    cout << fixed;
    cout.precision(6);
    cout << Answer;

    return 0;
}

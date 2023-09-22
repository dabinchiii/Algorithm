#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, h, w;
    cin >> d >> h >> w;

    double r = d / sqrt(h*h + w*w);

    cout << (int)(h * r) << ' ' << (int)(w * r);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    pair<int, int> Answer = {0, 0};
    for(int x=-999; x<=999; x++){
        for(int y=-999; y<=999; y++){
            int num1 = a * x + b * y;
            if(num1 != c) continue;

            int num2 = d * x + e * y;
            if(num2 != f) continue;

            Answer = {x, y};
        }
    }

    cout << Answer.first << ' ' << Answer.second;

    return 0;
}

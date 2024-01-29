#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double cost[] = {350.34, 230.90, 190.55, 125.30, 180.90};

    cout << fixed;
    cout.precision(2);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int cnt;
        double sum = 0;
        for(int i=0; i<5; i++){
            cin >> cnt;
            sum += (double)cnt * cost[i];
        }
        cout << '$' << sum << '\n';
    }

    return 0;
}

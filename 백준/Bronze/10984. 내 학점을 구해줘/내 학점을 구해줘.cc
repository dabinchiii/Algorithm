#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n;
        cin >> n;

        int c, totalC = 0;
        float g, sum = 0;
        for(int i=0; i<n; i++){
            cin >> c >> g;
            totalC += c;
            sum += (float)c * g;
        }
        float totalG = sum / (float)totalC;

        cout << fixed;
        cout.precision(1);
        cout << totalC << ' ' << totalG << '\n';
    }
    return 0;
}

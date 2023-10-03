#include <bits/stdc++.h>
#define MAX 10000
#define MIN -10000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int minX = MAX, maxX = MIN, minY = MAX, maxY = MIN;
    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;

        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    cout << abs(maxX - minX) * abs(maxY - minY);

    return 0;
}

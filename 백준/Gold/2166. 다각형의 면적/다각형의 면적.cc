#include <bits/stdc++.h>

using namespace std;

struct coord{
    long long x, y;
};

int n;
vector<struct coord> v;
long double ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    long long x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        v.push_back({x, y});
    }

    long double sumA, sumB;
    for(int i=1; i<n-1; i++){
        sumA = v[0].x * v[i].y + v[i].x * v[i+1].y + v[i+1].x * v[0].y;
        sumB = v[0].x * v[i+1].y + v[i].x * v[0].y + v[i+1].x * v[i].y;

        ans += (sumA - sumB) / 2;
    }
    ans = abs(ans);

    cout << fixed;
    cout.precision(1);

    cout << ans;

    return 0;
}

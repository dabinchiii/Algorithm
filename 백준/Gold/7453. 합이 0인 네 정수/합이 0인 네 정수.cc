#include <bits/stdc++.h>
#define MAX_N 4000

using namespace std;

int n;
int a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> sumAB, sumCD;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sumAB.push_back(a[i] + b[j]);
            sumCD.push_back(-(c[i] + d[j]));
        }
    }

    sort(sumAB.begin(), sumAB.end());
    sort(sumCD.begin(), sumCD.end());

    long long ans = 0;
    int leftCD, rightCD;
    for(int i=0; i<sumAB.size(); i++){
        leftCD = lower_bound(sumCD.begin(), sumCD.end(), sumAB[i]) - sumCD.begin();
        rightCD = upper_bound(sumCD.begin(), sumCD.end(), sumAB[i]) - sumCD.begin();

        ans += rightCD - leftCD;
    }

    cout << ans;

    return 0;
}

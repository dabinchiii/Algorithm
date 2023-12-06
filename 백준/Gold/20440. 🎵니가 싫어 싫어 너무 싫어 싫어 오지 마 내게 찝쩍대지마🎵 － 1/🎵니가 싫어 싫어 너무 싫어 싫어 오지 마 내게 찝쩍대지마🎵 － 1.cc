#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<int, int> m;

    int te, tx;
    for(int i=0; i<n; i++){
        cin >> te >> tx;
        m[te]++;
        m[tx]--;
    }

    vector<pair<int, int>> v;
    v.assign(m.begin(), m.end());

    sort(v.begin(), v.end());

    int maxCnt = -1;
    int maxStart, maxEnd;
    int curr = 0;
    for(int i=0; i<v.size(); i++){
        curr += v[i].second;

        if(curr > maxCnt){
            maxCnt = curr;
            maxStart = v[i].first;
            maxEnd = -1;
        }
        else if(curr < maxCnt && maxEnd == -1){
            maxEnd = v[i].first;
        }
    }

    cout << maxCnt << '\n';
    cout << maxStart << ' ' << maxEnd;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m;
    cin >> m;

    cout << (m + 1) / 2 << '\n';

    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap
    int median, cnt = 0;

    cin >> median;
    cout << median << ' ';

    int num;
    for(int i=2; i<=m; i++){
        cin >> num;

        if(num < median) left.push(num);
        else right.push(num);

        if(left.size() > right.size()){
            right.push(median);
            median = left.top();
            left.pop();
        }
        else if(left.size() < right.size()){
            left.push(median);
            median = right.top();
            right.pop();
        }

        if(i % 2) cout << median << ' ';
    }

    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        solve();
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    int p, d;
    for(int i=0; i<n; i++){
        cin >> p >> d;
        arr[i] = {d, p};
    }

    sort(arr.begin(), arr.end());

    priority_queue<int> q;
    int Answer = 0;
    for(int i=0; i<n; i++){
        q.push(-arr[i].second);
        Answer += arr[i].second;

        if((int)q.size() > arr[i].first){
            Answer += q.top();
            q.pop();
        }
    }

    cout << Answer;

    return 0;
}

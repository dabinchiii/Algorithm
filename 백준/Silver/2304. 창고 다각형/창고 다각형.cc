#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> a, const pair<int, int> b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    int l, h;
    for(int i=0; i<n; i++){
        cin >> l >> h;
        arr.push_back({l, h});
    }

    sort(arr.begin(), arr.end(), comp);

    int Answer = 0;
    pair<int, int> leftCurrMax = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i].second > leftCurrMax.second){
            Answer += leftCurrMax.second * (arr[i].first - leftCurrMax.first);
            leftCurrMax = arr[i];
        }
    }

    pair<int, int> rightCurrMax = arr[n-1];
    for(int i=n-2; i>=0; i--){
        if(arr[i].second > rightCurrMax.second){
            Answer += rightCurrMax.second * (rightCurrMax.first - arr[i].first);
            rightCurrMax = arr[i];
        }
    }

    Answer += leftCurrMax.second * (rightCurrMax.first - leftCurrMax.first + 1);

    cout << Answer;

    return 0;
}

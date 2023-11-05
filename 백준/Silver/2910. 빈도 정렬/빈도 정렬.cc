#include <bits/stdc++.h>
using namespace std;

map<int, int> m, first;

bool comp(const int a, const int b){
    if(m[a] != m[b]) return m[a] > m[b];
    return first[a] < first[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
        m[arr[i]]++;
        if(!first[arr[i]]){
            first[arr[i]] = i + 1;
        }
    }


    sort(arr.begin(), arr.end(), comp);

    for(int x : arr){
        cout << x << ' ';
    }

    return 0;
}

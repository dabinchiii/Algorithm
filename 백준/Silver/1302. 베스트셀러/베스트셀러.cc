#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    map<string, int> m;

    int maxValue = -1;
    string Answer = "";

    for(int i=0; i<n; i++){
        string curr = arr[i];

        m[curr]++;
        if(m[curr] > maxValue){
            maxValue = m[curr];
            Answer = curr;
        }
    }

    cout << Answer;

    return 0;
}

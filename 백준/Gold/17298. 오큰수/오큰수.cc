#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> Answer(n, -1);
    stack<int> stk;
    for(int i=0; i<n; i++){
        while(!stk.empty() && arr[stk.top()] < arr[i]){
            Answer[stk.top()] = arr[i];
            stk.pop();
        }

        stk.push(i);
    }

    for(int x : Answer){
        cout << x << ' ';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }

    int sumA = 0, sumB = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i] >= '0' && a[i] <= '9') sumA += a[i] - '0';
    }
    for(int i=0; i<b.length(); i++){
        if(b[i] >= '0' && b[i] <= '9') sumB += b[i] - '0';
    }

    if(sumA != sumB){
        return sumA < sumB;
    }

    return a < b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), comp);

    for(string x : arr){
        cout << x << '\n';
    }

    return 0;
}

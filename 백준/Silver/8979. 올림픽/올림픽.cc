#include <bits/stdc++.h>

using namespace std;

typedef struct nation{
    int gold, silver, bronze;
}nation;

bool operator==(const nation &a, const nation &b){
    return a.gold == b.gold && a.silver == a.silver && a.bronze == b.bronze;
}

bool cmp(const nation &a, const nation &b){
    if(a.gold != b.gold) return a.gold > b.gold;
    if(a.silver != b.silver) return a.silver > b.silver;
    return a.bronze > b.bronze;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<nation> arr(n);
    int no;
    for(int i=0; i<n; i++){
        cin >> no;
        no--;
        cin >> arr[no].gold >> arr[no].silver >> arr[no].bronze;
    }

    nation target = arr[k-1];

    sort(arr.begin(), arr.end(), cmp);

    for(int i=0; i<n; i++){
        if(arr[i] == target){
            cout << i + 1;
            break;
        }
    }

    return 0;
}

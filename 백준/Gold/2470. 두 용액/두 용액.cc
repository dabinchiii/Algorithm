#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

int n;
int val[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> val[i];
    }

    sort(val, val + n);

    int left = 0, right = n - 1;
    int minSum = 2000000000, sum;
    int ansIdx[2];
    while(left < right){
        sum = val[left] + val[right];
        if(abs(sum) < minSum){
            minSum = abs(sum);
            ansIdx[0] = left;
            ansIdx[1] = right;
        }

        if(sum < 0) left++;
        else if(sum > 0) right--;
        else break;
    }

    cout << val[ansIdx[0]] << ' ' << val[ansIdx[1]];

    return 0;
}

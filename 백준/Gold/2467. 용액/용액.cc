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

    int minValue = 2000000000;
    int AnswerL, AnswerR;
    int left, right, curr;

    AnswerL = left = 0;
    AnswerR = right = n - 1;

    while(left < right){
        curr = arr[left] + arr[right];
        if(abs(curr) < minValue){
            minValue = abs(curr);
            AnswerL = left;
            AnswerR = right;
        }

        if(curr == 0) break;
        else if(curr < 0) left++;
        else right--;
    }

    cout << arr[AnswerL] << ' ' << arr[AnswerR];

    return 0;
}

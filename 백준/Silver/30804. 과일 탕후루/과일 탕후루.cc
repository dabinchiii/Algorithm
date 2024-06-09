#include <bits/stdc++.h>
#define MAX_N 200000

using namespace std;

int n;
int tang[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tang[i];
    }

    int left = 0, right = 0;
    int kind = 0;
    int nums[10];
    int maxLen = 0;

    for(int i=0; i<10; i++) nums[i] = 0;

    while(right < n){
        if(nums[tang[right]] == 0) kind++;
        nums[tang[right]]++;

        while(kind > 2){
            nums[tang[left]]--;
            if(nums[tang[left]] == 0) kind--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);

        right++;
    }


    cout << maxLen;

    return 0;
}

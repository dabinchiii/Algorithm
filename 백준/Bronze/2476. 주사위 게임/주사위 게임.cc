#include <bits/stdc++.h>
using namespace std;

int nums[3];
int Answer = -1;

int getReward(){
    sort(nums, nums + 3);

    if(nums[0] == nums[2]){
        return 10000 + nums[0] * 1000;
    }
    if(nums[0] == nums[1] || nums[1] == nums[2]){
        return 1000 + nums[1] * 100;
    }
    return nums[2] * 100;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> nums[j];
        }
        Answer = max(Answer, getReward());
    }

    cout << Answer;

    return 0;
}

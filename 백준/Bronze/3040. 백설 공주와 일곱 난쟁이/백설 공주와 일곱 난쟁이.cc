#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums(9);
    int sum = 0;
    for(int i=0; i<9; i++){
        cin >> nums[i];
        sum += nums[i];
    }

    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(sum - nums[i] - nums[j] == 100){
                nums.erase(nums.begin() + j);
                nums.erase(nums.begin() + i);
            }
        }
    }

    for(auto it=nums.begin(); it!=nums.end(); it++){
        cout << *it << endl;
    }

    return 0;
}

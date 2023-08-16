#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    map<int, int> m;

    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        sum += nums[i];
        m[nums[i]]++;
    }

    sort(nums.begin(), nums.end()); // 오름차순

    int modeVal = -1;
    vector<int> mode;
    for(auto it=m.begin(); it!=m.end(); it++){
        if(it->second > modeVal){
            modeVal = it->second;
            mode.clear();
        }
        if(it->second == modeVal){
            mode.push_back(it->first);
        }
    }
    sort(mode.begin(), mode.end());
    int modeAns;
    if((int)mode.size() == 1){
        modeAns = mode[0];
    }
    else{
        modeAns = mode[1];
    }

    cout << (int)round((float)sum / n) << endl; // 산술평균
    cout << nums[n/2] << endl; // 중앙값
    cout << modeAns << endl;
    cout << nums[n-1] - nums[0]; // 범위



    return 0;
}

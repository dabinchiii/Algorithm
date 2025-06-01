#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct answer{
    long val;
    int s1, s2, s3;
};

int n;
long arr[5000];
answer ans;


void solve(){
    sort(arr, arr + n);
    
    ans = {3000000000, -1, -1, -1};
    
    for(int s1=0; s1<n - 2; s1++){
        for(int s2 = s1 + 1; s2<n - 1; s2++){
            int left = s2 + 1, right = n - 1;
            
            long sum;
            while(left <= right){
                int mid = (left + right) / 2;
                sum = arr[s1] + arr[s2] + arr[mid];
                
                if(abs(sum) < ans.val){
                    ans = {abs(sum), s1, s2, mid};
                }
                
                if(sum > 0){ // 작아지는 방향
                    right = mid - 1;
                }
                else if(sum < 0){ // 커지는 방향
                    left = mid + 1;
                }
                else{ // sum이 0
                    ans = {0, s1, s2, mid};
                    
                    return;
                }
                
            }
        }
    }
    
    return;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    solve();
    
    cout << arr[ans.s1] << ' ' << arr[ans.s2] << ' ' << arr[ans.s3];
    
    return 0;
}

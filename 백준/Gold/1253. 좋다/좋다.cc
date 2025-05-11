#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[2000];
int ans;

void solve(){
    sort(arr, arr + n);
    
    int left, right;
    for(int i=0; i<n; i++){
        left = 0;
        right = n - 1;
        
        while(left < right){
            int curr = arr[left] + arr[right];
            
            if(curr == arr[i]){
                if(left == i){
                    left++;
                    continue;
                }
                if(right == i){
                    right--;
                    continue;
                }
                
                ans++;
                break;
            }
            else if(curr < arr[i]){ // curr이 커져야 함
                left++;
            }
            else{ // curr이 작아져야 함
                right--;
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
    
    cout << ans;
    
    return 0;
}

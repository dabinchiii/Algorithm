#include <iostream>

#define MAX_N 100000

using namespace std;

int N, M;
int arr[MAX_N];
int ans;

bool check(int m){
    int curr = 0, sum = 0, cnt = 1;
    while(curr < N){
        if(arr[curr] > m) return false;
        
        sum += arr[curr];
        if(sum > m){
            ++cnt;
            sum = arr[curr];
        }
        ++curr;
    }
    
    return cnt <= M;
}

void solve(){
    
    int left = 1, right = 1000000005;
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        if(check(mid)){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    solve();
    
    cout << ans;
    
    return 0;
}

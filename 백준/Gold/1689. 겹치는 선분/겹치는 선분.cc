#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000000

using namespace std;

int N;
pair<int, bool> arr[MAX_N << 1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    int s, e;
    int len = N << 1;
    for(int i=0; i<len; i+=2){
        cin >> s >> e;
        arr[i] = {s, true}; // 더하기
        arr[i + 1] = {e, false}; // 빼기
    }
    
    sort(arr, arr + len);
    
    int ans = -1;
    int cnt = 0;
    for(int i=0; i<len; i++){
        if(arr[i].second){
            ++cnt;
            ans = max(ans, cnt);
        }
        else{
            --cnt;
        }
    }
    
    cout << ans;
    
    return 0;
}

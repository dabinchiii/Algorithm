#include <iostream>

using namespace std;

int n, k;
int arr[500000];
int ans = -1;

int cnt;

void merge(int start, int mid, int end){
    int tmp[500000];
    
    int p1 = start, p2 = mid + 1, idx = 0;
    while(p1 <= mid && p2 <= end){
        tmp[idx++] = (arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++]);
    }
    while(p1 <= mid){
        tmp[idx++] = arr[p1++];
    }
    while(p2 <= end){
        tmp[idx++] = arr[p2++];
    }
    
    p1 = start; idx = 0;
    while(p1 <= end){
        arr[p1++] = tmp[idx++];
        
        cnt++;
        if(cnt == k){
            ans = arr[p1 - 1];
            return;
        }
    }
    
    return;
}

void mergeSort(int start, int end){
    if(start >= end || ans != -1) return;
    
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, end);
    
    return;
}
int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    mergeSort(0, n - 1);
    
    cout << ans;
}


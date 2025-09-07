#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int N, M;
int arr[1000001];
ll *tree;

ll sum(int node, int start, int end, int left, int right){
    if(start > right || end < left) return 0; // 범위에 아예 포함되지 않는 구역
    
    if(start >= left && end <= right){ // 범위에 완전히 포함되는 구역
        return tree[node];
    }
    
    int mid = (start + end) / 2;
    ll leftSum = sum(2 * node, start, mid, left, right);
    ll rightSum = sum(2 * node + 1, mid + 1, end, left, right);
    
    return leftSum + rightSum;
}

void modify(int node, int start, int end, int idx, ll value){
    if(start > idx || end < idx) return;
    
    if(start == end){
        if(start == idx) tree[node] = value;
        return;
    }
    
    int mid = (start + end) / 2;
    modify(2 * node, start, mid, idx, value);
    modify(2 * node + 1, mid + 1, end, idx, value);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    int h = ceil(log2(N)) + 1;
    tree = new ll[1 << h];
    
    int q;
    for(int i=0; i<M; i++){
        cin >> q;
        
        if(q == 0){
            int i, j;
            cin >> i >> j;
            
            if(i > j) swap(i, j);
            
            printf("%ld\n", sum(1, 1, N, i, j));
        }
        else{
            int i;
            ll k;
            cin >> i >> k;
            
            modify(1, 1, N, i, k);
        }
    }
    
    return 0;
}

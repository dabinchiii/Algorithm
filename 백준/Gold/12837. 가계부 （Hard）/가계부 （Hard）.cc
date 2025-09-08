#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int N, Q;
ll arr[1000001];
ll *tree;

void update(int node, int start, int end, int idx, ll value){
    if(start > idx || end < idx) return;
    
    if(start == end){
        tree[node] += value;
        return;
    }
    
    int mid = (start + end) / 2;
    if(idx >= start && idx <= mid) update(2 * node, start, mid, idx, value);
    if(idx > mid && idx <= end) update(2 * node + 1, mid + 1, end, idx, value);
    
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    
    return;
}

ll sum(int node, int start, int end, int left, int right){
    if(start > right || end < left) return 0;
    
    if(start >= left && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    ll leftSum = sum(2 * node, start, mid, left, right);
    ll rightSum = sum(2 * node + 1, mid + 1, end, left, right);
    
    return leftSum + rightSum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> Q;
    
    int h = ceil(log2(N)) + 1;
    tree = new ll[1 << h];
    
    int q, a, b;
    for(int i=0; i<Q; i++){
        cin >> q >> a >> b;
        if(q == 1) update(1, 1, N, a, (ll)b);
        else printf("%lld\n", sum(1, 1, N, a, b));
    }
    
    return 0;
}

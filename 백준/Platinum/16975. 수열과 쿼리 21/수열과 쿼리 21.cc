#include <iostream>

#define MAX_N 100000

using namespace std;

int N, M;
int arr[MAX_N + 1];
long long tree[4 * MAX_N], lazy[4 * MAX_N];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = arr[l];
        return;
    }
    
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build((node << 1) + 1, mid + 1, r);
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
    
    return;
}
void push(int node, int l, int r){
    if(lazy[node] == 0) return;
    
    int mid = (l + r) >> 1;
    
    long long val = lazy[node];
    
    tree[node << 1] += val * (mid - l + 1); // l ~ mid 범위
    tree[(node << 1) + 1] += val * (r - mid); // mid+1 ~ r 범위
    lazy[node << 1] += val;
    lazy[(node << 1) + 1] += val;
    
    lazy[node] = 0;
    
    return;
}
void update(int node, int start, int end, int l, int r, int val){
    if(r < start || l > end) return; // 포함 X
    if(start <= l && r <= end){ // 완전히 포함
        tree[node] += val * (r - l + 1);
        lazy[node] += val;
        return;
    }
    
    push(node, l, r);
    
    int mid = (l + r) >> 1;
    update(node << 1, start, end, l, mid, val);
    update((node << 1) + 1, start, end, mid + 1, r, val);
    
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
    
    return;
}
long long query(int node, int start, int end, int l, int r){
    if(r < start || l > end) return 0; // 아예 포함되지 X
    if(start <= l && r <= end) return tree[node]; // 완전히 포함됨
    
    push(node, l, r);
    
    int mid = (l + r) >> 1;
    return query(node << 1, start, end, l, mid) + query((node << 1) + 1, start, end, mid + 1, r);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    for(int i=1; i<=N; i++) cin >> arr[i];
    build(1, 1, N);
    
    cin >> M;
    
    int comm, a, b, c;
    for(int i=0; i<M; i++){
        cin >> comm;
        
        if(comm == 1){
            cin >> a >> b >> c;
            update(1, a, b, 1, N, c);
        }
        else{
            cin >> a;
            cout << query(1, a, a, 1, N) << '\n';
        }
    }
    
    
    return 0;
}

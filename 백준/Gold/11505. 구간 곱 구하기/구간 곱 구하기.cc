#include <iostream>

#define MAX_N 1000000
#define MOD 1000000007

using namespace std;

int N, M, K;
long long arr[MAX_N], tree[2 * MAX_N];

void makeTree(){
    for(int i=0; i<N; i++) tree[i + N] = arr[i];
    for(int i=N-1; i>0; i--) tree[i] = (tree[i<<1] * tree[i<<1 | 1]) % MOD;
    return;
}
void update(int i, int x){
    tree[i += N] = x;
    while(i >>= 1) tree[i] = (tree[i<<1] * tree[i<<1 | 1]) % MOD;
    return;
}
int query(int l, int r){ // [l, r)
    int res = 1;
    for(l += N, r += N; l != r; l >>= 1, r >>= 1){
        if(l & 1) res = (res * tree[l++]) % MOD;
        if(r & 1) res = (res * tree[--r]) % MOD;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    
    for(int i=0; i<N; i++) cin >> arr[i];
    
    makeTree();
    
    int a, b, c;
    for(int i=M+K; i>0; i--){
        cin >> a >> b >> c;
        --b;
        
        if(a == 1) update(b, c);
        else cout << query(b, c) << '\n';
    }
    
    return 0;
}
